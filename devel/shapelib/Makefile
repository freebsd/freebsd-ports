# Created by: Randall Hopper <aa8vb@nc.rr.com>
# $FreeBSD$

PORTNAME=	shapelib
PORTVERSION=	1.4.0
CATEGORIES=	devel geography
MASTER_SITES=	http://download.osgeo.org/shapelib/ \
		ftp://ftp.remotesensing.org/shapelib/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C API for reading and writing ArcView Shapefiles

LICENSE=	LGPL20

OPTIONS_DEFINE=	DOCS PROJ
OPTIONS_SUB=	yes

MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool localbase pathfix

PORTDOCS=	*

PROJ_CONFIGURE_OFF=	--with-proj-cflags="" --with-proj-libs=""
PROJ_LIB_DEPENDS=	libproj.so:graphics/proj

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/shptest ${STAGEDIR}${PREFIX}/bin/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/web/*.html ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
