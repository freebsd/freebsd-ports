# New ports collection makefile for:	pinball
# Date created:		Tue 13 aug 2002 22:46:02 CEST
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	pinball
PORTVERSION=	0.1.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@pompo.net

.if !defined(WITH_ALLEGRO)
BUILD_DEPENDS=	${SDL_CONFIG}:${PORTSDIR}/devel/sdl12
LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer
.else
BUILD_DEPENDS=	${ALLEGRO_CONFIG}:${PORTSDIR}/devel/allegro
LIB_DEPENDS=	alleg.4:${PORTSDIR}/devel/allegro
.endif

USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_MESA=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}
.if defined(WITH_ALLEGRO)
CONFIGURE_ARGS+=	--with-allegro
.endif
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -L${X11BASE}/lib" \
		SDL_CONFIG="${SDL_CONFIG}"
SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
ALLEGRO_CONFIG=	${LOCALBASE}/bin/allegro-config

DOCS=		README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s:%%PREFIX%%:${PREFIX}:g"
	@${ECHO_MSG}

.include <bsd.port.mk>
