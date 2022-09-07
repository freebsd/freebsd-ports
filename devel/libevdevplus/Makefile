PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	0.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	7f208aaf21aa468013fc41e67c32f6a6c8c08249.patch:-p1 # install directives

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Easy-to-use event device library in C++
WWW=		https://github.com/YukiWorkshop/libevdevPlus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/uinput.h:devel/evdev-proto

USES=	cmake compiler:c++11-lang localbase

USE_GITHUB=	yes
GH_PROJECT=	libevdevPlus
GH_ACCOUNT=	YukiWorkshop

USE_LDCONFIG=	yes

.include <bsd.port.mk>
