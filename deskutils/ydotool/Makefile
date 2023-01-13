PORTNAME=	ydotool
PORTVERSION=	1.0.3
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic command-line automation tool (no X!)
WWW=		https://github.com/ReimuNotMoe/ydotool

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/uinput.h:devel/evdev-proto \
		scdoc:textproc/scdoc
LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim

USES=		cmake compiler:c++11-lang localbase

USE_GITHUB=	yes
GH_ACCOUNT=	ReimuNotMoe

CFLAGS+=	-I${LOCALBASE}/include/libepoll-shim
LDFLAGS+=	-L${LOCALBASE}/lib -lepoll-shim

PLIST_FILES=	bin/ydotool \
		bin/ydotoold \
		lib/systemd/user/ydotool.service \
		share/man/man1/ydotool.1.gz \
		share/man/man8/ydotoold.8.gz

.include <bsd.port.mk>
