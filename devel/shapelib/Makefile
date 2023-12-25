PORTNAME=	shapelib
PORTVERSION=	1.6.0
CATEGORIES=	devel geography
MASTER_SITES=	https://download.osgeo.org/shapelib/ \
		https://github.com/OSGeo/shapelib/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C API for reading and writing ArcView Shapefiles
WWW=		http://shapelib.maptools.org/ \
		https://github.com/OSGeo/shapelib

LICENSE=	LGPL20+ MIT
LICENSE_COMB=	dual
LICENSE_FILE_LGPL20+ =	${WRKSRC}/LICENSE-LGPL
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		libtool localbase pathfix

MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

# bin/dbfdump
CONFLICTS_INSTALL=	p5-DBD-XBase

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/shptest ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
