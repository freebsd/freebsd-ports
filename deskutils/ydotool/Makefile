PORTNAME=	ydotool
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic command-line automation tool (no X!)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/uinput.h:devel/evdev-proto \
		scdoc:textproc/scdoc
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim \
		libuInputPlus.so:devel/libuinputplus \
		libboost_program_options.so:devel/boost-libs \
		libevdevPlus.so:devel/libevdevplus

USES=		cmake compiler:c++11-lang localbase

USE_GITHUB=	yes
GH_ACCOUNT=	ReimuNotMoe

USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include/libepoll-shim
LDFLAGS+=	-L${LOCALBASE}/lib -lepoll-shim

PLIST_FILES=	bin/ydotool \
		bin/ydotoold \
		lib/systemd/user/ydotool.service \
		man/man1/ydotool.1.gz \
		man/man8/ydotoold.8.gz

.include <bsd.port.mk>
