PORTNAME=	adplug
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	2.4
CATEGORIES=	audio
PKGNAMEPREFIX=	lib

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	AdLib emulator library supporting many formats
WWW=		https://adplug.github.io/

LICENSE=	GPLv2

LIB_DEPENDS=	libbinio.so:devel/libbinio

USES=		autoreconf compiler:c++11-lang cpe libtool makeinfo \
		pkgconfig
CPE_VENDOR=	adplug_project
USE_CSTD=	gnu89
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-maintainer-mode

INSTALL_TARGET=	install-strip

INFO=		libadplug
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
