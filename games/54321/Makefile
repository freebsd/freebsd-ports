# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	54321
PORTVERSION=	1.0.2001.11.16
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	http://old.nklein.com/products/54321/${PORTVERSION}/ \
		http://www.sourcefiles.org/Games/Puzzle/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Five games in four-, three-, or two-dimensions for one player

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake sdl tar:tgz
USE_SDL=	image sdl
MAKEFILE=	GNUmakefile

post-extract:
	@${MKDIR} ${WRKSRC}/archs/${OPSYS}
	@${CP} ${FILESDIR}/variables.GNU ${WRKSRC}/archs/${OPSYS}

post-patch:
	@${REINPLACE_CMD} -e \
		's|ARCH|OPSYS| ; \
		 s|:= -O|+=|' ${WRKSRC}/GNUmakefile
	@${REINPLACE_CMD} -e \
		's|SDL_main|main| ; \
		 s|../../data/|${DATADIR}/data/|' ${WRKSRC}/code/*.cpp

do-install:
	(cd ${WRKSRC}/Release/bin/${OPSYS} && ${INSTALL_PROGRAM} 54321 \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DATADIR}/data
	(cd ${WRKSRC}/Release/data && ${INSTALL_DATA} * \
		${STAGEDIR}${DATADIR}/data)

.include <bsd.port.mk>
