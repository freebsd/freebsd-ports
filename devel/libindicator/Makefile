# $FreeBSD$

PORTNAME=	libindicator
PORTVERSION=	12.10.1
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Symbols and convience functions for desktop indicators

USES=		gmake gnome libtool pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS_powerpc64=	-Wno-unused-value
CFLAGS_powerpc=	-Wno-unused-value
CFLAGS_powerpcspe=	-Wno-unused-value
CFLAGS_mips=	-Wno-unused-value
CFLAGS_mips64=	-Wno-unused-value
CFLAGS_sparc64=	-Wno-unused-value

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
