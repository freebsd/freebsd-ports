# Created by: verm@drunkmonk.net
# $FreeBSD$

PORTNAME=	lmarbles
PORTVERSION=	1.0.8
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME} \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Atomix-like game of moving marbles in puzzles

LICENSE=	GPLv2

USE_SDL=	sdl mixer
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${ETCDIR}

MAN6=		${PORTNAME}.6

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog README README-SDL.txt

DOCSRCDIR2=	${WRKSRC}/src/manual
DOCSDIR2=	${DOCSDIR}/manual
DOC_FILES2=	*.jpg *.html

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|(datadir)/icons|(datadir)/pixmaps|g' \
	-e 's|(datadir)/pixmaps/lmarbles32.gif|(datadir)/pixmaps/lmarbles32.png|g' \
	-e 's|(datadir)/pixmaps/lmarbles48.gif|(datadir)/pixmaps/lmarbles48.png|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-m 666||g' \
	-e 's|lmarbles.prfs|lmarbles.prfs.sample|g' \
		${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}*.png ${PREFIX}/share/pixmaps/
	@if [ ! -f ${ETCDIR}/lmarbles.prfs ] ; then \
		${INSTALL_DATA} ${ETCDIR}/lmarbles.prfs.sample ${ETCDIR}/lmarbles.prfs ; \
	fi

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
