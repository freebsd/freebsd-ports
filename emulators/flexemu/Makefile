PORTNAME=	flexemu
DISTVERSIONPREFIX=	V
DISTVERSION=	3.20
CATEGORIES=	emulators

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	MC6809 emulator running FLEX operating system
WWW=		https://flexemu.neocities.org/

LICENSE=	GPLv2

USES=		desktop-file-utils gl libtool qt:5 shared-mime-info xorg
USE_GITHUB=	yes
GH_ACCOUNT=	aladur
GH_TUPLE=	google:googletest:e1a38bc3:googletest/googletest
USE_GL=		gl
USE_QT=		buildtools:build concurrent core dbus declarative \
		declarative-test designer gui help multimedia network \
		opengl printsupport qmake:build script scripttools \
		sensors serialport sql svg testlib widgets x11extras \
		xml xmlpatterns
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
