PORTNAME=	xcbautolock
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	deskutils x11

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	XCB base autolocker
WWW=		https://github.com/bapt/xcbautolock

LICENSE=	BSD2CLAUSE

USES=		pkgconfig
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	bapt

MAKE_ENV=	MANDIR=${PREFIX}/share/man/man1

LIB_DEPENDS=	libxcb-screensaver.so:x11/libxcb

PLIST_FILES=	bin/xcbautolock \
		share/man/man1/xcbautolock.1.gz

.include <bsd.port.mk>
