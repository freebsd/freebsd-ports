# New ports collection makefile for:	stratagus
# Date created:			30 Jun 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	stratagus
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	tlp@liquidx.org
COMMENT=	Free cross-platform real-time strategy gaming engine

BUILD_DEPENDS=	${LOCALBASE}/lib/libpng.a:${PORTSDIR}/graphics/png \
		${LOCALBASE}/lib/liblua.a:${PORTSDIR}/lang/lua

USE_SDL=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/stratagus-040702

GNU_CONFIGURE=	yes

.if defined(WITH_OPENGL)
CONFIGURE_ARGS+=	--with-opengl
.endif

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=	--without-ogg
.else
LIB_DEPENDS+=	vorbisfile.4:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITHOUT_MIKMOD)
CONFIGURE_ARGS+=	--without-mikmod
.else
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
.endif

PLIST_FILES=	bin/stratagus

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not run properly on FreeBSD 4.x
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Stratagus has the following tunable option(s):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_OPENGL=yes		Builds Stratagus with OpenGL"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITHOUT_VORBIS=yes	Turns off Ogg Vorbis support"
	@${ECHO_MSG} "	WITHOUT_MIKMOD=yes	Turns off Mikmod support"
	@${ECHO_MSG} ""

post-configure:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Rules.make
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|' ${WRKSRC}/Rules.make

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
