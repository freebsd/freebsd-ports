#
# Ports collection makefile for:	scorched3d
# Date created:				Jan 5, 2003
# Whom:					mdodd
#
# $FreeBSD$

PORTNAME=		scorched3d
PORTVERSION=		0.${SCORCH_VERSION}
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scorched3d
DISTNAME=		Scorched3D-${SCORCH_VERSION}-src

MAINTAINER=		mdodd@FreeBSD.org
COMMENT=		Scorched is a game based loosely on the classic DOS game

LIB_DEPENDS=		SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
			SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
			SDL_net.0:${PORTSDIR}/net/sdl_net \
			wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk-devel

SCORCH_VERSION=		35
WRKSRC=			${WRKDIR}/scorched
SDL_CONFIG?=		${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE= 		yes
USE_MESA=		yes
USE_GMAKE=		yes
USE_AUTOMAKE_VER=	15
USE_AUTOCONF_VER=	253

AUTOMAKE_ARGS=		--foreign
CONFIGURE_ARGS=		--with-wx-config=${X11BASE}/bin/wx-config
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
			SDL_CONFIG="${LOCALBASE}/bin/sdl11-config"
MAKE_ENV=		SDL_CONFIG="${LOCALBASE}/bin/sdl11-config"
MAKE_ARGS=		ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" \
			AUTOMAKE="${TRUE}" AUTOHEADER="${TRUE}"

pre-configure:
	@cd ${WRKSRC}/scripts && ${PERL} createAMMakefile.pl
	@cd ${WRKSRC} && aclocal

pre-install:
	@mkdir -p ${PREFIX}/games/scorched3d

post-install:
	@ln -fs ${PREFIX}/games/scorched3d/scorched3d ${PREFIX}/bin/scorched3d

.include <bsd.port.mk>
