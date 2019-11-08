# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	abe
PORTVERSION=	1.1
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abe's Amazing Adventure

LICENSE=	GPLv2

USES=		gmake sdl
USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-data-dir=${DATADIR}

MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS GOD_MODE OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	GOD_MODE OPTIMIZED_CFLAGS
GOD_MODE_DESC=	Enable God Mode (toggle with 'g')

DESKTOP_ENTRIES="Abe's Amazing Avanture" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%u|%zu|' ${WRKSRC}/src/MapIO.c

.if ${PORT_OPTIONS:MGOD_MODE} || ! ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
. if ${PORT_OPTIONS:MGOD_MODE}
	@${REINPLACE_CMD} -e 's|#define GOD_MODE 0|#define GOD_MODE 1|' \
		${WRKSRC}/src/Game.h
. endif
. if ! ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
	@${REINPLACE_CMD} -e 's|-O2||g ; \
		s|-fomit-frame-pointer||g ; \
		s|-ffast-math||g ; \
		s|-fexpensive-optimizations||g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
. endif
.endif

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.for d in images maps sounds
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
