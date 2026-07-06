PORTNAME=	libverto
DISTVERSION=	0.3.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/latchset/libverto/releases/download/${DISTVERSION}/

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Main event loop abstraction library
WWW=		https://github.com/latchset/libverto

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		libtool pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-libevent=default \
		--without-glib \
		--without-libev
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
