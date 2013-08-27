# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	abe
PORTVERSION=	1.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	nemysis@freebsd.org
COMMENT=	Abe's Amazing Adventure

LICENSE=	GPLv2

BUILD_DEPENDS=	bmptopnm:${PORTSDIR}/graphics/netpbm

USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-data-dir=${DATADIR}
USE_GMAKE=	yes

MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDATA=	*
PORTDOCS=	AUTHORS ChangeLog README

DESKTOP_ENTRIES="Abe's Amazing Avanture" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ${FALSE}

OPTIONS_DEFINE=	GOD_MODE OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS
GOD_MODE_DESC=	Enable God Mode (toggle with 'g')

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MGOD_MODE} || !empty(PORT_OPTIONS:MOPTIMIZED_CFLAGS)
.   if ${PORT_OPTIONS:MGOD_MODE}
	@${REINPLACE_CMD} -e 's|\(#define GOD_MODE\) 0|\1 1|' \
		${WRKSRC}/src/Game.h
.   endif
.   if empty(PORT_OPTIONS:MOPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|-O2||g ; \
		s|-fomit-frame-pointer||g ; \
		s|-ffast-math||g ; \
		s|-fexpensive-optimizations||g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.   endif
.endif

post-build:
	@(cd ${WRKSRC} && ${TAR} xf ./images/images.tar abe.bmp && \
		${LOCALBASE}/bin/bmptopnm abe.bmp | \
		${LOCALBASE}/bin/pamscale .2487 | ${LOCALBASE}/bin/pnmtopng > ${PORTNAME}.png)

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${PREFIX}/share/pixmaps
	${MKDIR} ${DATADIR}
.for d in images maps sounds
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
