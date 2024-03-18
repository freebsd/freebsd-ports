PORTNAME=	xtrojka
PORTVERSION=	1.2.3
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/arcade/tetris
DISTNAME=	${PORTNAME}${PORTVERSION:C/\.//g}

MAINTAINER=	ports@edwinm.ik.nu
COMMENT=	Game of skill similar to T*tris

USES=		xorg
USE_XORG=	x11 xt xorgproto xaw xmu xext

MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install PREFIX=${STAGEDIR}${PREFIX}

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.options.mk>

post-patch:
.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
	@${REINPLACE_CMD} -e 's|CFLAGS=|CFLAGS=-Wno-error=incompatible-function-pointer-types |g' \
		${WRKSRC}/Makefile
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xtrojka

.include <bsd.port.mk>
