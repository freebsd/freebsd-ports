# New ports collection makefile for:	allacrost
# Date created:		03 Oct 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	allacrost
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	allacrost_demo_source_${PORTVERSION}

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	A single player 2D role-playing game

BUILD_DEPENDS=	${LOCALBASE}/lib/libluabind.a:${PORTSDIR}/devel/luabind
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		openal.0:${PORTSDIR}/audio/openal \
		ogg.5:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LUA=	5.0
USE_SDL=	sdl ttf net
USE_GL=		yes
USE_GCC=	4.2+

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--datadir=${DATADIR}
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${LUA_LIBDIR}" \
		CPPFLAGS="-I${LOCALBASE}/include -I${LUA_INCDIR}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	MANUAL

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/include/|-I${LOCALBASE}/include/|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|exit -1|exit 1|; /CXXFLAGS=/ d; \
		s|-lSDL |`${SDL_CONFIG} --libs` |' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
