PORTNAME=	naev
PORTVERSION=	0.13.5
DISTVERSIONSUFFIX=	-source
CATEGORIES=	games
MASTER_SITES=	https://codeberg.org/naev/naev/releases/download/v${PORTVERSION}/:naev_source \
		LOCAL/acm/${PORTNAME}/:naev_cache
DISTFILES=	${PORTNAME}-${PORTVERSION}-source${EXTRACT_SUFX}:naev_source \
		${PORTNAME}-cache-${PORTVERSION}.tar.gz:naev_cache

MAINTAINER=	acm@FreeBSD.org
COMMENT=	2D action/RPG space game
WWW=		https://naev.org/

LICENSE=	GPLv2 GPLv3 CC-BY-3.0 CC-BY-SA-3.0 PD
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${RUST_DEFAULT}>=1.89:lang/${RUST_DEFAULT} \
		bindgen:devel/rust-bindgen-cli
LIB_DEPENDS=	libamd.so:math/suitesparse-amd \
		libblas.so:math/blas \
		libcholmod.so:math/suitesparse-cholmod \
		libcmark.so:textproc/cmark \
		libcolamd.so:math/suitesparse-colamd \
		libcxsparse.so:math/suitesparse-cxsparse \
		libenet.so:net/enet \
		libfreetype.so:print/freetype2 \
		libglpk.so:math/glpk \
		libmetis.so:math/metis \
		libopenblas.so:math/openblas \
		libpcre2-8.so:devel/pcre2 \
		libphysfs.so:devel/physfs \
		libpng.so:graphics/png \
		libunibreak.so:textproc/libunibreak \
		libvorbisfile.so:audio/libvorbis \
		libwebp.so:graphics/webp \
		libyaml.so:textproc/libyaml \
 		libzip.so:archivers/libzip
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>0:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		cmake:indirect desktop-file-utils gettext gl gnome localbase:ldflags \
		luajit meson openal pkgconfig python sdl \
		shebangfix tar:xz
USE_GL=		gl glu
USE_GNOME=	intltool libxml2
USE_LDCONFIG=	yes
USE_SDL=	sdl2 image2

SHEBANG_GLOB=	*.py *.sh

MESON_ARGS=	-Ddocs_c=disabled -Ddocs_lua=disabled

BINARY_ALIAS=	python3=${PYTHON_CMD}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|%%WRKDIR%%|${WRKDIR}|g' ${WRKSRC}/meson.build

.include <bsd.port.mk>
