# Created by: LoÃ¯c BARTOLETTI
# $FreeBSD$

PORTNAME=	pgmodeler
PORTVERSION=	0.9.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	PostgreSQL Database Modeler

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lib pgsql qmake pkgconfig gmake qt:5
USE_GITHUB=	yes

USE_GNOME=	libxml2
USE_QT=		gui network sql svg printsupport widgets core buildtools_build uitools testlib
USE_GL=		gl
USE_XORG=	x11 xext

USE_LDCONFIG=	yes

QMAKE_SOURCE_PATH=	${WRKSRC}/${PORTNAME}.pro

post-patch:
	@${REINPLACE_CMD} -e 's|linux|unix|g' ${WRKSRC}/${PORTNAME}.pri

pre-install:
	@${MKDIR} ${STAGEDIR}/${LOCALBASE}/lib/${PORTNAME}/plugins

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/tests

.include <bsd.port.mk>
