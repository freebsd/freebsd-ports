# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xworm
PORTVERSION=	1.02
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.ekran.no/archive/x/
DISTNAME=	${PORTNAME}102

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Classic game with apples and hungry worm

USES=		xorg
USE_XORG=	x11 xt
WRKSRC=		${WRKDIR}/XWorm
ALL_TARGET=	linux
MAKE_ARGS=	CC="${CC}" INCDIR="-I${LOCALBASE}/include" \
		LINUXFLAGS='${CFLAGS} -DXWORMDIR=\"${DATADIR}\"' \
		LINUXLINK="-L${LOCALBASE}/lib -lXt -lX11 -lm"

DATA=		font grid raw
PLIST_FILES=	bin/xworm \
		${DATA:S/^/%%DATADIR%%\/xworm./}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xworm ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xworm
.for file in ${DATA}
	${INSTALL_DATA} ${WRKSRC}/xworm.${file} ${STAGEDIR}${PREFIX}/share/xworm
.endfor

.include <bsd.port.mk>
