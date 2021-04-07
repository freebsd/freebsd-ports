PORTNAME=	libindicator
PORTVERSION=	12.10.1
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Symbols and convience functions for desktop indicators

USES=		compiler:c++11-lang gmake gnome libtool pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
