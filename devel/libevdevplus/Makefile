# $FreeBSD$

PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	0.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Easy-to-use event device library in C++

LICENSE=	MIT
LICENSE_FILES=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/uinput.h:devel/evdev-proto

USES=	cmake localbase

USE_GITHUB=	yes
GH_PROJECT=	libevdevPlus
GH_ACCOUNT=	YukiWorkshop

USE_LDCONFIG=	yes

.include <bsd.port.mk>
