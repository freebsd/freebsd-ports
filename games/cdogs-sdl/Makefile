PORTNAME=	cdogs-sdl
PORTVERSION=	0.10.2
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Classic overhead run-and-gun game

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=3,1:devel/py-protobuf@${PY_FLAVOR} \
		protoc:devel/protobuf

USES=		cmake compiler:c++11-lang gl gnome localbase:ldflags pkgconfig \
		python:3.6+ sdl

USE_SDL=	image2 mixer2 sdl2
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	cxong
CMAKE_ARGS=	-DCDOGS_DATA_DIR=${DATADIR}/

BINARY_ALIAS=	python3=${PYTHON_VERSION}

# Fix with clang11
CFLAGS+=	-fcommon

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cdogs-sdl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cdogs-sdl-editor

.include <bsd.port.mk>
