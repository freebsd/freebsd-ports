# Created by: verm@drunkmonk.net
# $FreeBSD$

PORTNAME=	lmarbles
PORTVERSION=	1.0.8
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME} \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Atomix-like game of moving marbles in puzzles

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_SDL=	sdl mixer
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/games/${PORTNAME}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|(datadir)/icons|(datadir)/pixmaps|; \
		s|(datadir)/pixmaps/lmarbles48.gif|(datadir)/pixmaps/lmarbles48.png|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-m 666||; \
		s|lmarbles.prfs|lmarbles.prfs.sample|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|icons/lmarbles48.gif|icons/lmarbles48.png|' \
		${WRKSRC}/lmarbles.desktop.in

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}*.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS ChangeLog README README-SDL.txt" ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} "manual" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
