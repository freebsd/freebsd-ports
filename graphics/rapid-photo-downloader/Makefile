# $FreeBSD$

PORTNAME=	rapid-photo-downloader
DISTVERSION=	0.9.26
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://launchpad.net/rapid/pyqt/${PORTVERSION}/+download/

MAINTAINER=	m.ne@gmx.net
COMMENT=	Import photos and videos efficiently and reliably

LICENSE=	GPLv3

BUILD_DEPENDS=	intltool-update:textproc/intltool
LIB_DEPENDS=	libgexiv2.so:graphics/gexiv2 \
		libgudev-1.0.so:devel/libgudev
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arrow>0:devel/py-arrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colour>0:graphics/py-colour@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>2.2:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}easygui>=0:x11-toolkits/py-easygui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gobject3>0:devel/py-gobject3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gphoto2>=1.4.0:graphics/py-gphoto2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gstreamer1>=1.0:multimedia/py-gstreamer1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notify2>0:devel/py-notify2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=3.4.2:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymediainfo>=1.0:multimedia/py-pymediainfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>0:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rawkit>0:graphics/py-rawkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>0:devel/py-sortedcontainers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>0:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.1:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR} \
		exiftool:graphics/p5-Image-ExifTool

USES=		desktop-file-utils gettext pyqt:5 python:3.6+ qt:5
USE_PYTHON=	autoplist distutils noflavors
USE_QT=		imageformats_run
USE_PYQT=	core gui network sip widgets
BINARY_ALIAS=	python3=${PYTHON_VERSION}

NO_ARCH=	yes

OPTIONS_DEFINE=		COLOUR PROGRESS
OPTIONS_DEFAULT=	COLOUR PROGRESS

COLOUR_DESC=	generates coloured program output
PROGRESS_DESC=	shows a progress bar on the command line

COLOUR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorlog>0:devel/py-colorlog@${PY_FLAVOR}
PROGRESS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyprind>=1.4.0:misc/py-pyprind@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e 's|'share/man/man1'|'man/man1'|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
