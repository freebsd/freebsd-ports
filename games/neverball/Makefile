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

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		vorbis:${PORTSDIR}/audio/libvorbis \
		physfs:${PORTSDIR}/devel/physfs

USE_GL=		gl
USE_SDL=	sdl ttf
USE_GMAKE=	yes
MAKE_ENV+=	ENABLE_WII=0
USE_XORG=	x11

PORTDOCS=	CHANGES COPYING README
MAN6=		neverball.6 neverputt.6

LDFLAGS+=	-lX11 # calls X functions directly, but doesn't link libX11

NO_STAGE=	yes
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
	@${MKDIR} ${DATADIR}/data
	@(cd ${WRKSRC}/data ; ${COPYTREE_SHARE} . ${DATADIR}/data/)
	@(cd ${WRKSRC}/dist ; ${INSTALL_MAN} ${MAN6} ${MAN6PREFIX}/man/man6/)
.for f in neverball neverputt
	@${INSTALL_DATA} ${WRKSRC}/dist/${f}.desktop \
		${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/dist/${f}_512.png \
		${PREFIX}/share/pixmaps/${f}.png
	@${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin/
.endfor
.if ${PORT_OPTIONS:MNLS}
.  for ii in ${LOCALE_DIRS}
	@${MKDIR} ${PREFIX}/share/locale/${ii}/LC_MESSAGES
	@${INSTALL_DATA} ${WRKSRC}/locale/${ii}/LC_MESSAGES/*.mo \
		${PREFIX}/share/locale/${ii}/LC_MESSAGES/
.  endfor
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
.  for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
