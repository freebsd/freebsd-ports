# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pillow
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Fork of the Python Imaging Library (PIL)

LICENSE=	PIL
LICENSE_NAME=	Standard PIL License
LICENSE_FILE=	${WRKSRC}/docs/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE=		FREETYPE JPEG LCMS PNG TIFF TKINTER WEBP
OPTIONS_DEFAULT=	FREETYPE JPEG PNG TKINTER

LCMS_DESC=		Little Color Management System
TKINTER_DESC=		Tkinter (Tcl/Tk) BitmapImage & PhotoImage support

FREETYPE_LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
JPEG_USES=		jpeg
LCMS_LIB_DEPENDS=	liblcms2.so:${PORTSDIR}/graphics/lcms2
TIFF_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff
TKINTER_USES=		tk:build
TKINTER_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter
TKINTER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter
WEBP_LIB_DEPENDS=	libwebp.so:${PORTSDIR}/graphics/webp

USE_GITHUB=		yes
USES=			python
USE_PYTHON=		autoplist concurrent distutils
PYDISTUTILS_SETUP=	${PYSETUP}
PYDISTUTILS_BUILD_TARGET=	build build_py build_ext

# we have to build and install everything in a single run,
# otherwise pillow's build_ext extension tries to be clever
# and messes up standard distutils behaviour...
NO_BUILD=		yes

GH_ACCOUNT=	python-pillow
GH_PROJECT=	${PORTNAME:C/p/P/}

CONFLICTS_INSTALL=	py*-imaging-*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFREETYPE}
PYDISTUTILS_BUILDARGS+=	--enable-freetype
.else
PYDISTUTILS_BUILDARGS+=	--disable-freetype
.endif

.if ${PORT_OPTIONS:MJPEG}
PYDISTUTILS_BUILDARGS+=	--enable-jpeg
.else
PYDISTUTILS_BUILDARGS+=	--disable-jpeg
.endif

.if ${PORT_OPTIONS:MLCMS}
PYDISTUTILS_BUILDARGS+=	--enable-lcms
.else
PYDISTUTILS_BUILDARGS+=	--disable-lcms
.endif

.if ${PORT_OPTIONS:MPNG}
PYDISTUTILS_BUILDARGS+=	--enable-zlib
.else
PYDISTUTILS_BUILDARGS+=	--disable-zlib
.endif

.if ${PORT_OPTIONS:MTIFF}
PYDISTUTILS_BUILDARGS+=	--enable-tiff
.else
PYDISTUTILS_BUILDARGS+=	--disable-tiff
.endif

.if ${PORT_OPTIONS:MTKINTER}
PYDISTUTILS_BUILDARGS+=	--enable-tcl --enable-tk \
			--include-dirs=${TCL_INCLUDEDIR}:${TK_INCLUDEDIR}
.else
PYDISTUTILS_BUILDARGS+=	--disable-tcl --disable-tk
.endif

.if ${PORT_OPTIONS:MWEBP}
PYDISTUTILS_BUILDARGS+=	--enable-webp
.else
PYDISTUTILS_BUILDARGS+=	--disable-webp
.endif

do-install:
	@(cd ${INSTALL_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYDISTUTILS_SETUP} ${PYDISTUTILS_BUILD_TARGET} ${PYDISTUTILS_BUILDARGS} \
		${PYDISTUTILS_INSTALL_TARGET} ${PYDISTUTILS_INSTALLARGS})

regression-test: extract
	@cd ${WRKSRC} && \
	${PYTHON_CMD} ${PYSETUP} build_ext -i && \
	${PYTHON_CMD} selftest.py

.include <bsd.port.mk>
