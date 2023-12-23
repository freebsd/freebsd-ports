PORTNAME=	libindicator
PORTVERSION=	12.10.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Symbols and convience functions for desktop indicators
WWW=		https://launchpad.net/libindicator

USES=		compiler:c++11-lang gmake gnome libtool pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
