# $FreeBSD$

PORTNAME=	neverball
PORTVERSION=	1.5.4
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org:9090/neverball/ \
		http://offload2.icculus.org:9090/neverball/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tilt the floor to guide a ball through an obstacle course

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libphysfs.so:${PORTSDIR}/devel/physfs

USES=		gmake
USE_GL=		gl
USE_SDL=	sdl ttf
MAKE_ENV+=	ENABLE_WII=0
USE_XORG=	x11

PORTDOCS=	CHANGES COPYING README
PORTDATA=	*

LDFLAGS+=	-lX11 # calls X functions directly, but doesn't link libX11

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
MAKE_ENV+=	ENABLE_NLS=1
LOCALE_DIRS=	ca de es fi fr lv nn
PLIST_SUB+=	NLS=""
.else
MAKE_ENV+=	ENABLE_NLS=0
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|./data|${DATADIR}/data|g; \
		s|./locale|${PREFIX}/share/locale|g; \
		s|sdl-config|${SDL_CONFIG}|g; \
		s| -O2| ${CFLAGS}|g; \
		s|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|%%ICONV_LIB%%|${ICONV_LIB}|' \
			${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/data
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}/
	${INSTALL_MAN} ${WRKSRC}/dist/*.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/
.for f in neverball neverputt
	${INSTALL_DATA} ${WRKSRC}/dist/${f}.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/dist/${f}_512.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${f}.png
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
.if ${PORT_OPTIONS:MNLS}
.  for ii in ${LOCALE_DIRS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${ii}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locale/${ii}/LC_MESSAGES/*.mo \
		${STAGEDIR}${PREFIX}/share/locale/${ii}/LC_MESSAGES/
.  endfor
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
