# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	heretic
PORTVERSION=	1.2
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://heretic.linuxgames.com/heretic/src/:source \
		http://heretic.linuxgames.com/wad/:wad
DISTNAME=	gl${PORTNAME}-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Unix source-port of the famous Heretic game by id Software

USE_XORG=	x11 xi xpm xau
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}

OPTIONS_DEFINE=	WAD
OPTIONS_SINGLE=	SG1
OPTIONS_SINGLE_SG1=	X11 FASTX11 SDL
FASTX11_DESC=	Use FastX11
WAD_DESC=	With shareware WAD
SG1_DESC=	Graphics Selections

OPTIONS_DEFAULT=	X11 WAD

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
ALL_TARGET=	x11
BINARY=		xheretic
.endif

.if ${PORT_OPTIONS:MFASTX11}
ALL_TARGET=	fastx11
BINARY=		xaheretic
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	yes
ALL_TARGET=	sdl
BINARY=		sdlheretic
CFLAGS+=	`${SDL_CONFIG} --cflags`
.endif

.if ${PORT_OPTIONS:MWAD}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source heretic_share.wad.gz:wad
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
PLIST_SUB=	WAD:=""
.else
PLIST_SUB=	WAD:="@comment "
.endif

post-extract:
.if ${PORT_OPTIONS:MWAD}
	@${GZIP_CMD} -dc ${_DISTDIR}/heretic_share.wad.gz \
		> ${WRKSRC}/heretic_share.wad
.endif
	@${FIND} ${WRKSRC} -name .depend -type f -delete
	@${RM} ${WRKSRC}/i_ipx.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${PREFIX}/bin/heretic
	${INSTALL_PROGRAM} ${WRKSRC}/sndserver ${PREFIX}/bin/sndserver
.if ${PORT_OPTIONS:MWAD}
	@${MKDIR} ${PREFIX}/share/heretic
	${INSTALL_DATA} ${WRKSRC}/heretic_share.wad ${PREFIX}/share/heretic
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in "End User License Heretic Source Code.txt" Gamekeys.txt README.txt AUTHORS SourceReadme.txt Changelog README.opengl
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
