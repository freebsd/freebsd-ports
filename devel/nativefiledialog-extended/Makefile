PORTNAME=	nativefiledialog-extended
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Native File Dialog Extended
WWW=		https://github.com/btzy/nativefiledialog-extended

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdbus-1.so:devel/dbus

USE_GITHUB=	yes
GH_ACCOUNT=	btzy

USES=		cmake pkgconfig
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=TRUE \
		-DNFD_PORTAL=TRUE

.include <bsd.port.mk>
