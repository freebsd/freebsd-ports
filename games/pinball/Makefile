# New ports collection makefile for:	pinball
# Date created:		Tue 13 aug 2002 22:46:02 CEST
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	pinball
PORTVERSION=	0.3.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@pompo.net
COMMENT=	Emilia Pinball is a free pinball game

PATCH_DEPENDS=	${DOS2UNIX}:${PORTSDIR}/converters/unix2dos
.if !defined(WITH_ALLEGRO)
BUILD_DEPENDS=	${SDL_CONFIG}:${PORTSDIR}/devel/sdl12
LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer
.else
BUILD_DEPENDS=	${ALLEGRO_CONFIG}:${PORTSDIR}/devel/allegro
LIB_DEPENDS=	alleg.41:${PORTSDIR}/devel/allegro
.endif

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_MESA=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX}
.if defined(WITH_ALLEGRO)
CONFIGURE_ARGS+=	--with-allegro
EXTRA_LIBS=	-lGL -lGLU
.endif
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include -DRZR_LIBSTATIC" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -L${X11BASE}/lib ${EXTRA_LIBS}" \
		SDL_CONFIG="${SDL_CONFIG}"
SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
ALLEGRO_CONFIG=	${LOCALBASE}/bin/allegro-config
DOS2UNIX=	${LOCALBASE}/bin/dos2unix

DOCS=		README

DOS2TR=		base/Private.h

post-patch:
.for FILE in ${DOS2TR}
	@${DOS2UNIX} ${WRKSRC}/${FILE}
.endfor

post-install:
	@${MV} ${PREFIX}/bin/${MACHINE_ARCH}-unknown-freebsd${OSREL}-pinball \
		${PREFIX}/bin/pinball
	@${MV} ${PREFIX}/bin/${MACHINE_ARCH}-unknown-freebsd${OSREL}-pinball-config \
		${PREFIX}/bin/pinball-config
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===>   Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
