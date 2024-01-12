PORTNAME=	boxfort
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Convenient and cross-platform sandboxing C library
WWW=		https://github.com/Snaipe/BoxFort

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		powerpc powerpc64 powerpc64le
NOT_FOR_ARCHS_REASON=	configure error: Problem encountered: Architecture "ppc64" is not supported (and similar messages about other architectures)

USES=		meson
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Snaipe
GH_PROJECT=	BoxFort

PLIST_FILES=	include/boxfort.h \
		lib/libboxfort.so \
		libdata/pkgconfig/boxfort.pc

.include <bsd.port.mk>
