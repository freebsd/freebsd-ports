PORTNAME=	pillow
PORTVERSION=	10.4.0
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fork of the Python Imaging Library (PIL)
WWW=		https://python-pillow.org/ \
		https://github.com/python-pillow/Pillow

LICENSE=	PIL
LICENSE_NAME=	Standard PIL License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0,1:devel/py-pytest@${PY_FLAVOR}

USES=		cpe jpeg localbase python
USE_PYTHON=	autoplist concurrent pep517

CPE_VENDOR=	python

OPTIONS_DEFINE=	FREETYPE IMAGEQUANT JPEG2000 LCMS OLE PNG RAQM TIFF TKINTER WEBP XCB
OPTIONS_DEFAULT=FREETYPE IMAGEQUANT JPEG2000 LCMS OLE PNG RAQM TIFF TKINTER WEBP XCB
IMAGEQUANT_DESC=	Image Quantization support
LCMS_DESC=		Little Color Management System
OLE_DESC=		Microsoft OLE2 file format support
RAQM_DESC=		Complex text layout support
TKINTER_DESC=		Tkinter (Tcl/Tk) BitmapImage & PhotoImage support
XCB_DESC=		X11 screengrab support

FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_VARS=		PYDISTUTILS_BUILDARGS+=--enable-freetype
FREETYPE_VARS_OFF=	PYDISTUTILS_BUILDARGS+=--disable-freetype
IMAGEQUANT_LIB_DEPENDS=	libimagequant.so:graphics/libimagequant
IMAGEQUANT_VARS=	PYDISTUTILS_BUILDARGS+=--enable-imagequant
IMAGEQUANT_VARS_OFF=	PYDISTUTILS_BUILDARGS+=--disable-imagequant
JPEG2000_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
JPEG2000_VARS=		PYDISTUTILS_BUILDARGS+=--enable-jpeg2000
JPEG2000_VARS_OFF=	PYDISTUTILS_BUILDARGS+=--disable-jpeg2000
LCMS_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS_VARS=		PYDISTUTILS_BUILDARGS+=--enable-lcms
LCMS_VARS_OFF=		PYDISTUTILS_BUILDARGS+=--disable-lcms
OLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}olefile>=0:devel/py-olefile@${PY_FLAVOR}
PNG_VARS=		PYDISTUTILS_BUILDARGS+=--enable-zlib
PNG_VARS_OFF=		PYDISTUTILS_BUILDARGS+=--disable-zlib
RAQM_LIB_DEPENDS=	libraqm.so:print/libraqm
RAQM_VARS=		PYDISTUTILS_BUILDARGS+=--enable-raqm
RAQM_VARS_OFF=		PYDISTUTILS_BUILDARGS+=--disable-raqm
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_VARS=		PYDISTUTILS_BUILDARGS+=--enable-tiff
TIFF_VARS_OFF=		PYDISTUTILS_BUILDARGS+=--disable-tiff
TKINTER_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${PY_FLAVOR}
TKINTER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${PY_FLAVOR}
TKINTER_USES=		tk
TKINTER_VARS=		PYDISTUTILS_BUILDARGS+="--include-dirs=${TCL_INCLUDEDIR}:${TK_INCLUDEDIR}"
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_VARS=		PYDISTUTILS_BUILDARGS+="--enable-webp --enable-webpmux"
WEBP_VARS_OFF=		PYDISTUTILS_BUILDARGS+="--disable-webp --disable-webpmux"
XCB_USE=		XORG=xcb
XCB_USES=		xorg
XCB_VARS=		PYDISTUTILS_BUILDARGS+=--enable-xcb
XCB_VARS_OFF=		PYDISTUTILS_BUILDARGS+=--disable-xcb

.include <bsd.port.pre.mk>

PYDISTUTILS_BUILD_TARGET=	build build_ext
PYDISTUTILS_BUILDARGS+=		saveopts

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

do-test:
	cd ${WRKSRC} && ${SETENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} ${PYTHON_CMD} selftest.py

.include <bsd.port.post.mk>
