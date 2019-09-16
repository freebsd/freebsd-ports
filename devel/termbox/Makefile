# Created by: Adam Saponara <as@php.net>
# $FreeBSD$

PORTNAME=	termbox
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.2
CATEGORIES=	devel

MAINTAINER=	as@php.net
COMMENT=	Legacy-free alternative to ncurses

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		waf
USE_GITHUB=	yes
GH_ACCOUNT=	nsf
USE_LDCONFIG=	yes

PLIST_FILES=	include/termbox.h \
		lib/libtermbox.so.1.0.0 \
		lib/libtermbox.so.1 \
		lib/libtermbox.so \
		lib/libtermbox.a

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtermbox.so.1.0.0

.include <bsd.port.mk>
