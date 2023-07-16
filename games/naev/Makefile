PORTNAME=	naev
PORTVERSION=	0.10.6
PORTREVISION=	1
DISTVERSIONSUFFIX=	-source
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

USES=		desktop-file-utils gettext gl gnome luajit:luajit-openresty \
		meson openal pkgconfig python sdl tar:xz
USE_GL=		gl glu
USE_GNOME=	intltool libxml2
USE_SDL=	sdl2 image2

# work around meson not looking for headers/libs in /usr/local
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MESON_ARGS=	-Ddocs_c=disabled -Ddocs_lua=disabled

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	${REINPLACE_CMD} 's|python3|${PYTHON_VERSION}|g' ${WRKSRC}/meson.build

.include <bsd.port.mk>
