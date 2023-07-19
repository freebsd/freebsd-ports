PORTNAME=	xroach
PORTVERSION=	4.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://cyber.dabamos.de/pub/distfiles/
DISTNAME=	${PORTNAME}

MAINTAINER=	kidon@posteo.de
COMMENT=	Cockroaches hide under your windows

USES=		imake localbase xorg
USE_CSTD=	gnu99
USE_XORG=	x11 xext

DPADD+=		${LOCALBASE}/lib/libX11.a ${LIBM}
LDADD+=		-lX11 -lm

BINDIR=		${LOCALBASE}/bin
MANDIR=		${LOCALBASE}/man/man
BINOWN=		bin
BINMODE=	755

PLIST_FILES=	bin/xroach man/man6/xroach.6.gz

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-install:
	${INSTALL_PROGRAM} -s ${WRKSRC}/xroach ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man ${STAGEDIR}${MAN6PREFIX}/man/man6/${PORTNAME}.6

.include <bsd.port.mk>
