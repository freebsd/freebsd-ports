PORTNAME=	makedepend
PORTVERSION=	1.0.9
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Dependency generator for makefiles
WWW=		https://www.x.org/archive/X11R7.5/doc/man/man1/makedepend.1.html

LICENSE=	MIT

USES=		tar:xz xorg xorg-cat:util
USE_XORG=	xorgproto

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/makedepend share/man/man1/makedepend.1.gz

.include <bsd.port.mk>
