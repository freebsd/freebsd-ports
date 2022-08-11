PORTNAME=	boxfort
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Convenient and cross-platform sandboxing C library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		meson
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Snaipe
GH_PROJECT=	BoxFort

PLIST_FILES=	include/boxfort.h \
		lib/libboxfort.so \
		libdata/pkgconfig/boxfort.pc

.include <bsd.port.mk>
