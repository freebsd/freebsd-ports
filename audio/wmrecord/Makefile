# Created by: Konstantinos Konstantinidis <kkonstan@daemon.gr>
# $FreeBSD$

PORTNAME=	wmrecord
PORTVERSION=	1.0.5
PORTREVISION=	3
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://linkinnovations.linux.tucows.com/files/x11/dock/ \
		http://www.bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose audio recording utility for the WindowMaker dock

USES=		xorg
USE_XORG=	xpm x11 xext
MAKE_ARGS=	LIBS="-L${LOCALBASE}/lib -lXpm -lX11 -lXext" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" LIBDIR=""

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

PLIST_FILES=	bin/wmrecord man/man1/wmrecord.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmrecord ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/wmrecord.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
