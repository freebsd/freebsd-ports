# New ports collection makefile for:	allacrost
# Date created:		03 Oct 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	allacrost
PORTVERSION=	0.1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	allacrost_demo_source_${PORTVERSION}

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	A single player 2D role-playing game

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LUA=	5.0
USE_SDL=	sdl ttf mixer
USE_GL=		yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--datadir=${DATADIR}
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib -L${LUA_LIBDIR}" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include -I${LUA_INCDIR}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
USE_GCC=	4.0+
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|exit -1|exit 1|; /CXXFLAGS=/ d; \
		s|-lSDL |`${SDL_CONFIG} --libs` |' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|DATADIR|"${DATADIR}"|' ${WRKSRC}/src/main.cpp

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
