# New ports collection makefile for:	stratagus
# Date created:			30 Jun 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	stratagus
PORTVERSION=	2.2.5.5
CATEGORIES=	games
MASTER_SITES=	http://launchpadlibrarian.net/59493540/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free cross-platform real-time strategy gaming engine

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

OPTIONS=	MIKMOD "Enable Mikmod support" off \
		MNG "Enable MNG support" off \
		THEORA "Enable Theora support" off \
		VORBIS "Enable Ogg Vorbis support" on

LICENSE=	GPLv2
USE_GCC=	4.4+
USE_LUA=	5.0+
USE_SDL=	sdl
USE_GL=		gl
USE_AUTOTOOLS=	aclocal autoheader autoconf
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-extra-includes=${LUA_INCDIR} \
		--with-extra-libs=${LUA_LIBDIR} \
		--without-gles
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*
PLIST_FILES=	bin/stratagus

.include <bsd.port.pre.mk>

.if defined(WITH_MIKMOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
CONFIGURE_ARGS+=--with-mikmod
.else
CONFIGURE_ARGS+=--without-mikmod
.endif

.if defined(WITH_MNG)
LIB_DEPENDS+=	mng.1:${PORTSDIR}/graphics/libmng
CONFIGURE_ARGS+=--with-mng
.else
CONFIGURE_ARGS+=--without-mng
.endif

.if defined(WITH_THEORA)
LIB_DEPENDS+=	theora.0:${PORTSDIR}/multimedia/libtheora
CONFIGURE_ARGS+=--with-theora
.else
CONFIGURE_ARGS+=--without-theora
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbisfile.6:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-vorbis
.else
CONFIGURE_ARGS+=--without-vorbis
.endif

pre-configure:
	@(cd ${WRKSRC}; ./autogen.sh)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stratagus ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc; ${COPYTREE_SHARE} . ${DOCSDIR})
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
