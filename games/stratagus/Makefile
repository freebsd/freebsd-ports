# New ports collection makefile for:	stratagus
# Date created:			30 Jun 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	stratagus
PORTVERSION=	2.2.2
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free cross-platform real-time strategy gaming engine

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_LUA=	5.0
USE_SDL=	sdl
USE_GL=		gl
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LUA_INCDIR}
CONFIGURE_ENV=	LDFLAGS="-L${LUA_LIBDIR} -lm"

OPTIONS=	OPENGL "Enable OpenGL support" on \
		MIKMOD "Enable Mikmod support" off \
		VORBIS "Enable Ogg Vorbis support" off

PLIST_FILES=	bin/stratagus

.include <bsd.port.pre.mk>

.if defined(WITH_OPENGL)
CONFIGURE_ARGS+=--with-opengl
.endif

.if defined(WITH_MIKMOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
.else
CONFIGURE_ARGS+=--without-mikmod
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbisfile.5:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=--without-ogg
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||; s|gcc|${CC}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
