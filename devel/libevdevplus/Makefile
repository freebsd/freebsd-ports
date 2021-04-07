PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	0.1.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Easy-to-use event device library in C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/uinput.h:devel/evdev-proto

USES=	cmake compiler:c++11-lang localbase

USE_GITHUB=	yes
GH_PROJECT=	libevdevPlus
GH_ACCOUNT=	YukiWorkshop

USE_LDCONFIG=	yes

.include <bsd.port.mk>
