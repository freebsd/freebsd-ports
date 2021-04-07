PORTNAME=	ydotool
PORTVERSION=	0.1.8
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic command-line automation tool (no X!)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/uinput.h:devel/evdev-proto
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libuInputPlus.so:devel/libuinputplus \
		libboost_program_options.so:devel/boost-libs \
		libevdevPlus.so:devel/libevdevplus

USES=		cmake compiler:c++11-lang localbase

CXXFLAGS+=	-I${LOCALBASE}/include/libepoll-shim
LDFLAGS+=	-L${LOCALBASE}/lib -lepoll-shim

USE_GITHUB=	yes
GH_ACCOUNT=	ReimuNotMoe

PLIST_FILES=	bin/ydotool \
		bin/ydotoold \
		lib/libydotool.so \
		lib/libydotool.so.0

USE_LDCONFIG=	yes

.include <bsd.port.mk>
