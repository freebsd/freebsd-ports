# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	naev
PORTVERSION=	0.5.3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	2D action/RPG space game

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libvorbisfile.so:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/ndata-${PORTVERSION}:${PORTSDIR}/games/naev-data

USES=		gmake pkgconfig
USE_AUTOTOOLS=	automake:env aclocal:env autoconf:env
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GL=		glu
USE_GNOME=	libxml2
USE_SDL=	sdl image

CONFIGURE_ARGS=	--with-ndata-path=${DATADIR}/ndata-${PORTVERSION}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN6=		naev.6
PLIST_FILES=	bin/${PORTNAME}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	OPENAL SDL_MIXER
SDL_MIXER_DESC=	SDL_mixer sound backend

OPTIONS_DEFINE=	OPENAL SDL_MIXER

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENAL}
USES+=			openal
CONFIGURE_ARGS+=	--with-openal=yes
.else
CONFIGURE_ARGS+=	--with-openal=no
.endif

.if ${PORT_OPTIONS:MSDL_MIXER}
USE_SDL+=		mixer
CONFIGURE_ARGS+=	--with-sdlmixer=yes
.else
CONFIGURE_ARGS+=	--with-sdlmixer=no
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${MAN6PREFIX}/man/man6

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
