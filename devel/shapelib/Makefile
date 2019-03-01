# Created by: Randall Hopper <aa8vb@nc.rr.com>
# $FreeBSD$

PORTNAME=	shapelib
PORTVERSION=	1.5.0
CATEGORIES=	devel geography
MASTER_SITES=	https://download.osgeo.org/shapelib/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C API for reading and writing ArcView Shapefiles

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

USES=		libtool localbase pathfix

MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/shptest ${STAGEDIR}${PREFIX}/bin/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/web/* ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
