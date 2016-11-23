# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mypaint
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/mypaint/mypaint/releases/download/${PORTVERSION:S/^/v/}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast painting/scribbling program

LICENSE=	GPLv2+ ISCL
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_ISCL=	${WRKSRC}/brushlib/COPYING

BUILD_DEPENDS=	swig13>0:devel/swig13 \
		${PYNUMPY}
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		liblcms2.so:graphics/lcms2
RUN_DEPENDS=	${PYNUMPY}

USE_GNOME=	gtk30 pygobject3 librsvg2:run
CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_gcc=	-std=c99
MAKE_ARGS=	prefix=${PREFIX} \
		enable_profiling=False \
		use_sharedlib=True \
		python_binary="${PYTHON_CMD}" \
		python_config="${PYTHON_CMD}-config"
# XXX Embed RPATH via USES=fortran for py-numpy to load libgcc_s.so from ports
USES=		desktop-file-utils fortran gettext localbase \
		pkgconfig python:2 scons tar:xz
INSTALL_TARGET=	${STAGEDIR} --install-sandbox=${STAGEDIR}
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		GEGL OPENMP
OPTIONS_DEFAULT=	OPENMP
OPTIONS_SUB=		yes

GEGL_DESC=		Graph based image processing framework support
GEGL_LIB_DEPENDS=	libgegl-0.3.so:graphics/gegl3
GEGL_MAKE_ARGS=		enable_gegl=True

OPENMP_USES=		compiler:openmp
OPENMP_USES_OFF=	compiler # XXX ports/199603
OPENMP_MAKE_ARGS_OFF=	enable_openmp=False

post-install:
	${INSTALL_LIB} ${WRKSRC}/brushlib/libmypaint*.so ${STAGEDIR}${PREFIX}/lib
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mypaint/_mypaintlib.so

.include <bsd.port.mk>
