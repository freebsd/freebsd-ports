PORTNAME=	qt5
PORTVERSION=	5.15.9
CATEGORIES=	devel linux
PKGNAMEPREFIX=	linux-${linux_ARGS}-

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Cross-platform application and UI framework, metaport (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.qt.io/

LICENSE=	BSD2CLAUSE

USES=		linux:rl9 metaport
USE_LINUX=	qt3d qtbase qtconnectivity qtdeclarative qtgraphicaleffects \
		qtimageformats qtmultimedia qtquickcontrols qtscript qtsensors \
		qtserialbus qtserialport qtsvg qttools qtwayland \
		qtwebchannel qtwebsockets qtx11extras qtxmlpatterns

DESCR=		${PORTSDIR}/devel/${PORTNAME}/pkg-descr

.include <bsd.port.options.mk>

.include <bsd.port.mk>
