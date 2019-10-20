# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pillow
PORTVERSION=	6.2.0
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Fork of the Python Imaging Library (PIL)

LICENSE=	PIL
LICENSE_NAME=	Standard PIL License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR}

# Python 2.7,3.5+
USES=		cpe python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	python-${PORTNAME}
GH_PROJECT=	${PORTNAME:C/p/P/}

OPTIONS_DEFINE=		FREETYPE JPEG JPEG2000 LCMS OLE PNG TIFF TKINTER WEBP
OPTIONS_DEFAULT=	FREETYPE JPEG JPEG2000 LCMS OLE PNG TIFF TKINTER WEBP

LCMS_DESC=		Little Color Management System
OLE_DESC=		Microsoft OLE2 file format support
TKINTER_DESC=		Tkinter (Tcl/Tk) BitmapImage & PhotoImage support

FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_VARS=		PYDISTUTILS_BUILDARGS+=--enable-freetype
FREETYPE_VARS_OFF=	PYDISTUTILS_BUILDARGS+=--disable-freetype

JPEG_USES=		jpeg
JPEG_VARS=		PYDISTUTILS_BUILDARGS+=--enable-jpeg
JPEG_VARS_OFF=		PYDISTUTILS_BUILDARGS+=--disable-jpeg

JPEG2000_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
JPEG2000_VARS=		PYDISTUTILS_BUILDARGS+=--enable-jpeg2000
JPEG2000_VARS_OFF=	PYDISTUTILS_BUILDARGS+=--disable-jpeg2000

LCMS_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS_VARS=		PYDISTUTILS_BUILDARGS+=--enable-lcms
LCMS_VARS_OFF=		PYDISTUTILS_BUILDARGS+=--disable-lcms

OLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}olefile>0:devel/py-olefile@${PY_FLAVOR}

PNG_VARS=		PYDISTUTILS_BUILDARGS+=--enable-zlib
PNG_VARS_OFF=		PYDISTUTILS_BUILDARGS+=--disable-zlib

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_VARS=		PYDISTUTILS_BUILDARGS+=--enable-tiff
TIFF_VARS_OFF=		PYDISTUTILS_BUILDARGS+=--disable-tiff

TKINTER_USES=		tk
TKINTER_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}
TKINTER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}
TKINTER_VARS=		PYDISTUTILS_BUILDARGS+="--include-dirs=${TCL_INCLUDEDIR}:${TK_INCLUDEDIR}"

WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_VARS=		PYDISTUTILS_BUILDARGS+="--enable-webp --enable-webpmux"
WEBP_VARS_OFF=		PYDISTUTILS_BUILDARGS+="--disable-webp --disable-webpmux"

.include <bsd.port.pre.mk>

PYDISTUTILS_BUILD_TARGET=	build build_ext
PYDISTUTILS_BUILDARGS+=		saveopts

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PIL/*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.post.mk>
