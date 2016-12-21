# Created by: LoÃ¯c BARTOLETTI
# $FreeBSD$

PORTNAME=	pgmodeler
PORTVERSION=	0.8.2
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	PostgreSQL Database Modeler

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes

USES=		compiler:c++11-lib execinfo pgsql qmake pkgconfig gmake
USE_GNOME=	libxml2
USE_QT5=	gui network sql svg printsupport widgets core buildtools_build uitools testlib
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

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000 && ${OSVERSION} < 1002000
BROKEN=		does not build on FreeBSD 10.1 (src/databaseexplorerwidget.cpp:1604:88: error: chosen constructor is explicit in copy-initialization)
.endif

.include <bsd.port.post.mk>
