PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	0.1.4
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Easy-to-use uinput library in C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/uinput.h:devel/evdev-proto

USES=		cmake compiler:c++11-lang localbase

USE_GITHUB=	yes
GH_ACCOUNT=	YukiWorkshop
GH_PROJECT=	libuInputPlus

USE_LDCONFIG=	yes

.include <bsd.port.mk>
