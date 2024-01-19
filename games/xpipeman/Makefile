PORTNAME=	xpipeman
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/strategy
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Connect the pipes to stop the leaks

LICENSE=	MIT

USES=		imake tar:Z xorg
USE_XORG=	x11 xaw xext xmu xt sm ice

CFLAGS+=	-Wno-error=return-type

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpipeman ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xpipeman.man ${STAGEDIR}${PREFIX}/share/man/man6/xpipeman.6
	${INSTALL} -c ${FILESDIR}/xpipescores ${STAGEDIR}${PREFIX}/lib/X11

.include <bsd.port.mk>
