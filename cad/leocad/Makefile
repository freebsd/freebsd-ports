# New ports collection makefile for:	leocad
# Date created:				27 Jan 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	leocad
PORTVERSION=	0.73
CATEGORIES=	cad
MASTER_SITES=	http://www.leocad.org/files/ \
		http://people.freebsd.org/~scottl/
DISTFILES=	leocad-${PORTVERSION:S/.p/pre/}.tgz pieces.zip
EXTRACT_ONLY=	leocad-${PORTVERSION:S/.p/pre/}.tgz

MAINTAINER=	dyeske@yahoo.com

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

BROKEN=		Unknown problem

USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_MESA=	yes
USE_X_PREFIX=	yes

MAKE_ENV+=	CXX=${CXX}

post-extract:
	@unzip -q -o ${DISTDIR}/pieces.zip -d ${WRKDIR}/pieces

post-patch:
	@${PERL} -pi -e 's,%%LOCALBASE%%,${LOCALBASE},g; \
		s,%%PTHREAD_CFLAGS%%,${PTHREAD_CFLAGS},; \
		s,%%PTHREAD_LIBS%%,${PTHREAD_LIBS},' ${WRKSRC}/config.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/leocad ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/pieces/* ${DATADIR}

.include <bsd.port.mk>
