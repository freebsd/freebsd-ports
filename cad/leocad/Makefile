# New ports collection makefile for:	leocad
# Date created:				27 Jan 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	leocad
PORTVERSION=	0.73
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved
DISTFILES=	leocad-${PORTVERSION:S/.p/pre/}.tgz leocad-pieces-20030330.zip
EXTRACT_ONLY=	leocad-${PORTVERSION:S/.p/pre/}.tgz

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A CAD program that uses bricks similar to those found in many toys

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes

MAKE_ENV+=	CXX=${CXX}

post-extract:
	@unzip -q -o ${DISTDIR}/leocad-pieces-20030330.zip -d ${WRKDIR}/pieces

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
		${WRKSRC}/config.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/leocad ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/pieces/* ${DATADIR}

.include <bsd.port.mk>
