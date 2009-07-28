# New ports collection makefile for:	chapping
# Date created:		01 Aug 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	chapping
PORTVERSION=	0.43
CATEGORIES=	games
MASTER_SITES=	http://forja.rediris.es/frs/download.php/760/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Turn based board football game

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl image gfx ttf

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-source
ALL_TARGET=	linux

post-patch:
	@${REINPLACE_CMD} -e 's|make|${GMAKE}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^CXX=/ d; s|^SDL=.*|SDL=${SDL_CONFIG}|; \
		/\.o:/ d; /^CXXFLAGS=/ s|=-g -Wall -O2|+=|' \
		${WRKSRC}/library/Makefile ${WRKSRC}/game/Makefile
	@${REINPLACE_CMD} -e 's|menuimg/|${DATADIR}/&|; s|themes/|${DATADIR}/&|' \
		${WRKSRC}/game/*.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chapping ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "menuimg themes" ${DATADIR}/

.include <bsd.port.mk>
