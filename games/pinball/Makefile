# New ports collection makefile for:	pinball
# Date created:		Tue 13 aug 2002 22:46:02 CEST
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	pinball
PORTVERSION=	0.3.1
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Emilia Pinball is a free pinball game

.if !defined(WITH_ALLEGRO)
BUILD_DEPENDS=	${SDL_CONFIG}:${PORTSDIR}/devel/sdl12
.else
BROKEN=		support with Allegro is (temporarily) broken as of version 0.3.1
BUILD_DEPENDS=	${ALLEGRO_CONFIG}:${PORTSDIR}/devel/allegro
LIB_DEPENDS=	alleg.42:${PORTSDIR}/devel/allegro
.endif

USE_SDL=	image mixer sdl
USE_GMAKE=	yes
USE_GL=		gl
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} --without-debug
.if defined(WITH_ALLEGRO)
CONFIGURE_ARGS+=	--with-allegro
EXTRA_LIBS=	-lGL -lGLU
.endif
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -DRZR_LIBSTATIC" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${EXTRA_LIBS}"
MAKE_JOBS_UNSAFE=	yes
ALLEGRO_CONFIG=	${LOCALBASE}/bin/allegro-config

DOCS=		README

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===>   Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
