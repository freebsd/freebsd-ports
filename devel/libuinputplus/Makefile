PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	0.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	265e406e254c8d84016b12b344d8df71d1765dd1.patch:-p1 # install directives

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Easy-to-use uinput library in C++
WWW=		https://github.com/YukiWorkshop/libuInputPlus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/uinput.h:devel/evdev-proto

USES=		cmake compiler:c++11-lang localbase

USE_GITHUB=	yes
GH_ACCOUNT=	YukiWorkshop
GH_PROJECT=	libuInputPlus

USE_LDCONFIG=	yes

.include <bsd.port.mk>
