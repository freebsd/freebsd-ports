# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pillow
PORTVERSION=	2.5.1
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/p/P/}-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Fork of the Python Imaging Library (PIL)

LICENSE=	PIL
LICENSE_NAME=	Standard PIL License
LICENSE_FILE=	${WRKSRC}/docs/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE=		FREETYPE JPEG LCMS PNG TIFF TKINTER WEBP
OPTIONS_DEFAULT=	FREETYPE JPEG PNG

LCMS_DESC=		Little Color Management System
TKINTER_DESC=		Tkinter (Tcl/Tk) BitmapImage & PhotoImage support

FREETYPE_LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
JPEG_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
LCMS_LIB_DEPENDS=	liblcms2.so:${PORTSDIR}/graphics/lcms2
TIFF_LIB_DEPENDs=	libtiff.so:${PORTSDIR}/graphics/tiff
TKINTER_USES=		tk:build
WEBP_LIB_DEPENDS=	libwebp.so:${PORTSDIR}/graphics/webp

USE_GITHUB=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PYDISTUTILS_AUTOPLIST=		yes
PYDISTUTILS_BUILD_TARGET=	build_ext

GH_ACCOUNT=	python-pillow
GH_PROJECT=	${PORTNAME:C/p/P/}
GH_COMMIT=	1ab78b8

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

regression-test: extract
	@cd ${WRKSRC} && \
	${PYTHON_CMD} ${PYSETUP} build_ext -i && \
	${PYTHON_CMD} selftest.py

.include <bsd.port.mk>
