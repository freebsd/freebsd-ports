PORTNAME=	pillow
PORTVERSION=	11.3.0
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fork of the Python Imaging Library (PIL)
WWW=		https://python-pillow.github.io/ \
		https://pillow.readthedocs.io/en/stable/ \
		https://github.com/python-pillow/Pillow

LICENSE=	MIT-CMU
LICENSE_NAME=	CMU License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0,1:devel/py-pytest@${PY_FLAVOR}

USES=		cpe jpeg localbase python
USE_PYTHON=	autoplist concurrent pep517 pytest

PEP517_BUILD_CONFIG_SETTING=	\
		--config-setting jpeg=enable \
		--config-setting zlib=enable
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

CPE_VENDOR=	python

OPTIONS_DEFINE=	AVIF FREETYPE IMAGEQUANT JPEG2000 LCMS OLE RAQM TIFF TKINTER WEBP XCB
OPTIONS_DEFAULT=AVIF FREETYPE IMAGEQUANT JPEG2000 LCMS OLE RAQM TIFF TKINTER WEBP XCB
IMAGEQUANT_DESC=Image Quantization support
LCMS_DESC=	Little Color Management System
OLE_DESC=	Microsoft OLE2 file format support
RAQM_DESC=	Complex text layout support
TKINTER_DESC=	Tkinter (Tcl/Tk) BitmapImage & PhotoImage support
XCB_DESC=	X11 screengrab support

AVIF_LIB_DEPENDS=	libavif.so:graphics/libavif
AVIF_VARS=		PEP517_BUILD_CONFIG_SETTING+="--config-setting avif=enable"
AVIF_VARS_OFF=		PEP517_BUILD_CONFIG_SETTING+="--config-setting avif=disable"
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_VARS=		PEP517_BUILD_CONFIG_SETTING+="--config-setting freetype=enable"
FREETYPE_VARS_OFF=	PEP517_BUILD_CONFIG_SETTING+="--config-setting freetype=disable"
IMAGEQUANT_LIB_DEPENDS=	libimagequant.so:graphics/libimagequant
IMAGEQUANT_VARS=	PEP517_BUILD_CONFIG_SETTING+="--config-setting imagequant=enable"
IMAGEQUANT_VARS_OFF=	PEP517_BUILD_CONFIG_SETTING+="--config-setting imagequant=disable"
JPEG2000_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
JPEG2000_VARS=		PEP517_BUILD_CONFIG_SETTING+="--config-setting jpeg2000=enable"
JPEG2000_VARS_OFF=	PEP517_BUILD_CONFIG_SETTING+="--config-setting jpeg2000=disable"
LCMS_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS_VARS=		PEP517_BUILD_CONFIG_SETTING+="--config-setting lcms=enable"
LCMS_VARS_OFF=		PEP517_BUILD_CONFIG_SETTING+="--config-setting lcms=disable"
OLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}olefile>=0:devel/py-olefile@${PY_FLAVOR}
RAQM_LIB_DEPENDS=	libraqm.so:print/libraqm
RAQM_VARS=		PEP517_BUILD_CONFIG_SETTING+="--config-setting raqm=enable"
RAQM_VARS_OFF=		PEP517_BUILD_CONFIG_SETTING+="--config-setting raqm=disable"
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_VARS=		PEP517_BUILD_CONFIG_SETTING+="--config-setting tiff=enable"
TIFF_VARS_OFF=		PEP517_BUILD_CONFIG_SETTING+="--config-setting tiff=disable"
TKINTER_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${PY_FLAVOR}
TKINTER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${PY_FLAVOR}
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_VARS=		PEP517_BUILD_CONFIG_SETTING+="--config-setting webp=enable"
WEBP_VARS_OFF=		PEP517_BUILD_CONFIG_SETTING+="--config-setting webp=disable"
XCB_USE=		XORG=xcb
XCB_USES=		xorg
XCB_VARS=		PEP517_BUILD_CONFIG_SETTING+="--config-setting xcb=enable"
XCB_VARS_OFF=		PEP517_BUILD_CONFIG_SETTING+="--config-setting xcb=disable"

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
