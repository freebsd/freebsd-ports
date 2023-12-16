PORTNAME=	naev
PORTVERSION=	0.10.6
DISTVERSIONSUFFIX=	-source
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	https://github.com/naev/naev/releases/download/v${PORTVERSION}/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	2D action/RPG space game
WWW=		https://naev.org/

LICENSE=	GPLv2 GPLv3 CC-BY-3.0 CC-BY-SA-3.0 PD
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}
LIB_DEPENDS=	libamd.so:math/suitesparse-amd \
		libbacktrace.so:devel/libbacktrace \
		libblas.so:math/blas \
		libcholmod.so:math/suitesparse-cholmod \
		libcolamd.so:math/suitesparse-colamd \
		libcxsparse.so:math/suitesparse-cxsparse \
		libenet.so:net/enet \
		libfreetype.so:print/freetype2 \
		libglpk.so:math/glpk \
		libopenblas.so:math/openblas \
		libpcre2-8.so:devel/pcre2 \
		libphysfs.so:devel/physfs \
		libpng.so:graphics/png \
		libunibreak.so:textproc/libunibreak \
		libvorbisfile.so:audio/libvorbis \
		libwebp.so:graphics/webp \
 		libzip.so:archivers/libzip
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		desktop-file-utils gettext gl gnome localbase:ldflags \
		luajit:luajit-openresty meson openal pkgconfig python sdl \
		shebangfix tar:xz
USE_GL=		gl glu
USE_GNOME=	intltool libxml2
USE_SDL=	sdl2 image2

SHEBANG_GLOB=	*.py *.sh

MESON_ARGS=	-Ddocs_c=disabled -Ddocs_lua=disabled

BINARY_ALIAS=	python3=${PYTHON_CMD}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
