# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mypaint
DISTVERSIONPREFIX=v
DISTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/garynthompson/${PORTNAME}/commit/
# GTK input grab fix
PATCHFILES=	94c623b788462fadb3e292b918edc4e90adf4faa.patch:-p1

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Fast painting/scribbling program

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig:devel/swig \
		mypaint-brushes2>0:graphics/mypaint-brushes2 \
		${PYNUMPY}
LIB_DEPENDS=	libjson-c.so:devel/json-c \
		liblcms2.so:graphics/lcms2 \
		libpng16.so:graphics/png \
		libmypaint.so:graphics/libmypaint
RUN_DEPENDS=	mypaint-brushes2>0:graphics/mypaint-brushes2 \
		${PYNUMPY}

USES=		compiler:c++11-lib desktop-file-utils gettext gnome localbase \
		pkgconfig python:3.6+ tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	mypaint

USE_GNOME=	gtk30 pygobject3 cairo librsvg2:run
USE_PYTHON=	distutils py3kplist noflavors
PYDISTUTILS_BUILD_TARGET=	build build_ext
CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_gcc=	-std=c99
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	OPENMP
OPTIONS_DEFAULT_amd64=	OPENMP

OPENMP_USES=			compiler:openmp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mypaint/lib/_mypaintlib*.so

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MOPENMP}
PYDISTUTILS_BUILDARGS+=	--disable-openmp
.endif

.include <bsd.port.mk>
