# Created by: verm@drunkmonk.net
# $FreeBSD$

PORTNAME=	lmarbles
PORTVERSION=	1.0.8
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME} \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Atomix-like game of moving marbles in puzzles

LICENSE=	GPLv2

USES=		gmake
USE_SDL=	sdl mixer
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${ETCDIR}

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog README README-SDL.txt

DOCSRCDIR2=	${WRKSRC}/src/manual
DOCSDIR2=	${DOCSDIR}/manual
DOC_FILES2=	*.jpg *.html

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

	@${CHMOD} -R 464 ${STAGEDIR}${ETCDIR}/lmarbles.prfs.sample
	@${CHOWN} root:games ${STAGEDIR}${ETCDIR}/lmarbles.prfs.sample

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
