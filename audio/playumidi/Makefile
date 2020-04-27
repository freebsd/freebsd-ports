# Created by: Koine Yuusuke(koinec) <koinec@yahoo.co.jp>
# $FreeBSD$

PORTNAME=		playumidi
PORTVERSION=		0.8.2
CATEGORIES=		audio
MASTER_SITES=		OSDN/playumidi/71406

MAINTAINER=		koinec@users.osdn.me
COMMENT=		Standard MIDI format 0/1 player for FreeBSD USB-MIDI(umidi) device

LICENSE=		BSD2CLAUSE
LICENSE_FILE=		${WRKSRC}/LICENSE

PLIST_FILES=		bin/playumidi man/man1/playumidi.1.gz

OPTIONS_DEFINE=		LIBICONV DEBUG
OPTIONS_DEFAULT=	LIBICONV

LIBICONV_DESC=		Enable encoing conversion support with libiconv

DEBUG_MAKE_ARGS=	-DWITH_DEBUG

LIBICONV_LIB_DEPENDS=	libiconv.so:converters/libiconv
LIBICONV_MAKE_ARGS=	-DWITH_ICONV

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/playumidi ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/playumidi.1.gz ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
