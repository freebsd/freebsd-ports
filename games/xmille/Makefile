PORTNAME=	xmille
PORTVERSION=	2.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X window mille bourne game

LICENSE=	NONE

USES=		imake xorg
USE_XORG=	x11 xext

MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-Wno-error=return-type

WRKSRC=		${WRKDIR}/Mille

PLIST_FILES=	bin/xmille share/man/man1/xmille.1.gz

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-extract:
	@${FIND} ${WRKSRC} -name '*.[ao]' -delete

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmille ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmille.man ${STAGEDIR}${PREFIX}/share/man/man1/xmille.1

.include <bsd.port.mk>
