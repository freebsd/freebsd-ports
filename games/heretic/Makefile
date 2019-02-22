# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	heretic
PORTVERSION=	1.2
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://files.kyle-evans.net/freebsd/:source \
		http://files.kyle-evans.net/freebsd/:wad
DISTNAME=	gl${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Unix source-port of the famous Heretic game by id Software

USES=		dos2unix gmake
DOS2UNIX_FILES=	opengl/gl_struct.h

OPTIONS_DEFINE=		WAD DOCS
OPTIONS_SINGLE=		SG1
OPTIONS_SINGLE_SG1=	X11 FASTX11 SDL

FASTX11_DESC=		Use FastX11
WAD_DESC=		With shareware WAD
SG1_DESC=		Graphics Selections

OPTIONS_DEFAULT=	X11 WAD
OPTIONS_SUB=		yes

X11_ALL_TARGET=		x11
X11_VARS=		BINARY=xheretic
X11_USE=		XORG=x11,xext

FASTX11_ALL_TARGET=	fastx11
FASTX11_VARS=		BINARY=xaheretic
FASTX11_USE=		XORG=x11,xext

SDL_ALL_TARGET=		sdl
SDL_USES=		sdl
SDL_VARS=		BINARY=sdlheretic
SDL_CFLAGS=		`${SDL_CONFIG} --cflags`
SDL_USE=		SDL=sdl

WAD_DISTFILES=		heretic_share.wad.gz:wad

post-extract:
	@${FIND} ${WRKSRC} -name .depend -type f -delete
	@${RM} ${WRKSRC}/i_ipx.c

post-extract-WAD-on:
	@${GZIP_CMD} -dc ${_DISTDIR}/heretic_share.wad.gz \
		> ${WRKSRC}/heretic_share.wad

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${STAGEDIR}${PREFIX}/bin/heretic
	${INSTALL_PROGRAM} ${WRKSRC}/sndserver ${STAGEDIR}${PREFIX}/bin/sndserver

do-install-WAD-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/heretic
	${INSTALL_DATA} ${WRKSRC}/heretic_share.wad ${STAGEDIR}${PREFIX}/share/heretic

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in "End User License Heretic Source Code.txt" Gamekeys.txt README.txt AUTHORS SourceReadme.txt Changelog README.opengl
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
