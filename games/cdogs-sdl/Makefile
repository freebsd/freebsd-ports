PORTNAME=	cdogs-sdl
DISTVERSION=	2.0.0
CATEGORIES=	games

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Classic overhead run-and-gun game
WWW=		https://github.com/cxong/cdogs-sdl

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=3,1:devel/py-protobuf@${PY_FLAVOR} \
		protoc:devel/protobuf

USES=		cmake compiler:c++11-lang desktop-file-utils gl gnome localbase:ldflags pkgconfig \
		python sdl
USE_GITHUB=	yes
GH_ACCOUNT=	cxong
USE_GL=		gl
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_SDL=	image2 mixer2 sdl2

CMAKE_ARGS=	-DCDOGS_DATA_DIR=${DATADIR}/

BINARY_ALIAS=	python3=${PYTHON_VERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cdogs-sdl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cdogs-sdl-editor

.include <bsd.port.mk>
