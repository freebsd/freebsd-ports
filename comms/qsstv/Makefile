# ports collection makefile for:	qsstv
# Date created:		28 August 2004
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	qsstv
PORTVERSION=	5.3a
CATEGORIES=	comms
MASTER_SITES=	http://users.telenet.be/on4qz/download/

MAINTAINER=	db@db.net
COMMENT=	Amateur Radio SSTV/FAX reception program for unix

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_QT_VER=	3
CONFIGURE_ARGS=	--with-extra-includes=${LOCALBASE}/include --with-extra-libs=${LOCALBASE}/lib --infodir=${DOCSDIR}

do-install:
	${INSTALL_PROGRAM} -m 755 ${WRKSRC}/qsstv/qsstv ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/qsstv/docs/en/*.png ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/qsstv/docs/en/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
