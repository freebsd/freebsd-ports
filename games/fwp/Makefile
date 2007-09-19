# New ports collection makefile for:	fightwinprevail
# Date created:		06 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	fwp
PORTVERSION=	0.0.8
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fightwinprevail
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Multiplayer first person shooter

BUILD_DEPENDS=	${X11BASE}/lib/libode.a:${PORTSDIR}/devel/ode
LIB_DEPENDS=	OgreMain.13:${PORTSDIR}/graphics/ogre3d12

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_SDL=	sdl net mixer
USE_GCC=	3.4+

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		SDL_CONFIG="${SDL_CONFIG}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" && ${OSVERSION} >= 700000
BROKEN=		Doesn't build
.endif

post-patch:
	@${REINPLACE_CMD} -e '/LDFLAGS=/ s|$$LIBS|$$LDFLAGS|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O$$enable_optimize||' ${WRKSRC}/configure

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
