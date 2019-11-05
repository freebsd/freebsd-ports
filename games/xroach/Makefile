# Created by: markm
# $FreeBSD$

PORTNAME=	xroach
PORTVERSION=	4.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://cyber.dabamos.de/pub/distfiles/
DISTNAME=	${PORTNAME}

MAINTAINER=	kidon@posteo.de
COMMENT=	Cockroaches hide under your windows

DPADD+=		${LOCALBASE}/lib/libX11.a ${LIBM}
CFLAGS+=	-I${LOCALBASE}/include
LDADD+=		-L${LOCALBASE}/lib -lX11 -lm

MANDIR=		${LOCALBASE}/man/man

BINOWN=		bin
BINDIR=		${LOCALBASE}/bin
BINMODE=	755

USES=		imake xorg
USE_XORG=	x11 xext
USE_CSTD=	gnu99
PLIST_FILES=	bin/xroach man/man6/xroach.6.gz

do-install:
	${INSTALL_PROGRAM} -s ${WRKSRC}/xroach ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man ${STAGEDIR}${MAN6PREFIX}/man/man6/${PORTNAME}.6

.include <bsd.port.mk>
