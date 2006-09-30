# New ports collection makefile for:	stratagus
# Date created:			30 Jun 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	stratagus
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	tlp@liquidx.org
COMMENT=	Free cross-platform real-time strategy gaming engine

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_LUA=	5.0
USE_SDL=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CFLAGS=		-I${LUA_INCDIR}
LDFLAGS=	-L${LUA_LIBDIR}
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" \
		EXTRA_CFLAGS="${CFLAGS}" EXTRA_LIBS="${LDFLAGS}"
WRKSRC=		${WRKDIR}/stratagus-040702

OPTIONS=	OPENGL "Enable OpenGL support" on \
		MIKMOD "Enable Mikmod support" off \
		VORBIS "Enable Ogg Vorbis support" off

PLIST_FILES=	bin/stratagus

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not run properly on FreeBSD 4.x
.endif

.if defined(WITH_OPENGL)
CONFIGURE_ARGS+=--with-opengl
.endif

.if defined(WITH_MIKMOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
.else
CONFIGURE_ARGS+=--without-mikmod
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbisfile.4:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=--without-ogg
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
