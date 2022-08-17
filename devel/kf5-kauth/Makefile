PORTNAME=	kauth
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 abstraction to system policy and authentication features

USES=		cmake compiler:c++11-lib cpe kde:5 qt:5 tar:xz
CPE_VENDOR=	kde
USE_KDE=	coreaddons \
		ecm:build
USE_QT=		core dbus gui linguisttools widgets \
		buildtools:build qmake:build

OPTIONS_DEFINE=		POLKIT
OPTIONS_DEFAULT=	POLKIT
OPTIONS_SUB=		yes
POLKIT_DESC=		Polkit Qt support

OPTIONS_EXCLUDE_purecap=	POLKIT

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPOLKIT}
LIB_DEPENDS=	libpolkit-qt5-core-1.so:sysutils/polkit-qt
.endif

.include <bsd.port.post.mk>
