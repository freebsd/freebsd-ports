# New ports collection makefile for:	esdl
# Date Created:				2 January 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	esdl
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}.src
DIST_SUBDIR=	erlang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A library for accessing SDL and OpenGL through Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_DOS2UNIX=	Makefile
USE_GL=		gl glu
USE_GMAKE=	yes
USE_SDL=	sdl
ALL_TARGET=	target
PLIST_SUB=	VERSION="${PORTVERSION}"

OPTIONS=	SDL_TTF "SDL_ttf support" on \
		SDL_IMAGE "SDL_image support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SDL_TTF)
USE_SDL+=	ttf
PLIST_SUB+=	SDL_TTF=""
.else
PLIST_SUB+=	SDL_TTF="@comment "
.endif

.if !defined(WITHOUT_SDL_IMAGE)
USE_SDL+=	image
PLIST_SUB+=	SDL_IMAGE=""
.else
PLIST_SUB+=	SDL_IMAGE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's|addons|lib|' ${WRKSRC}/Makefile
.if !defined(WITHOUT_SDL_TTF)
	@${REINPLACE_CMD} -e '/ENABLE_SDL_TTF = / s|no|yes|' ${WRKSRC}/Makefile
.endif
.if !defined(WITHOUT_SDL_IMAGE)
	@${REINPLACE_CMD} -e '/ENABLE_SDL_IMAGE = / s|no|yes|' ${WRKSRC}/Makefile
.endif

post-install:
	@${LN} -sf ${PORTNAME}-${PORTVERSION} ${PREFIX}/lib/erlang/lib/${PORTNAME}

.include <bsd.port.post.mk>
