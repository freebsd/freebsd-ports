PORTNAME=	termbox
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.4
CATEGORIES=	devel

MAINTAINER=	as@php.net
COMMENT=	Library for writing text-based user interfaces
WWW=		https://github.com/termbox/termbox/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	include/termbox.h \
		lib/libtermbox.so.1.0.0 \
		lib/libtermbox.so.1 \
		lib/libtermbox.so \
		lib/libtermbox.a

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtermbox.so.1.0.0

.include <bsd.port.mk>
