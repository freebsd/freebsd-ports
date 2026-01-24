PORTNAME=	tulip
PORTVERSION=	6.0.1
DISTVERSIONSUFFIX=	_src
CATEGORIES=	graphics
MASTER_SITES=	SF/auber/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	System dedicated to the visualization of huge graphs
WWW=		https://tulip.labri.fr/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=0:devel/py-sip@${PY_FLAVOR}
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libqhull_r.so:math/qhull \
		libyajl.so:devel/yajl \
		libzip.so:archivers/libzip
RUN_DEPENDS=	bash:shells/bash

USES=		cmake desktop-file-utils gl pkgconfig python qt:6 \
		shared-mime-info shebangfix

USE_GL=		gl glew opengl
USE_QT=		5compat base

CMAKE_ON=	TULIP_USE_QT6

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
SHEBANG_FILES=	tulip-config.in
PLIST_SUB=	TULIP_VERSION="${PORTVERSION}" \
		TULIP_VERS="${PORTVERSION:R}"

.include <bsd.port.mk>
