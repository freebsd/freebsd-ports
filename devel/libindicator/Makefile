PORTNAME=	libindicator
DISTVERSION=	12.10.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Symbols and convience functions for desktop indicators
WWW=		https://launchpad.net/libindicator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gmake gnome libtool pkgconfig
USE_GNOME=	cairo gdkpixbuf gtk30
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
