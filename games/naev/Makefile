# New ports collection makefile for:	naev
# Date created:		2009-04-26
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	naev
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A 2d action/rpg space game

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/ndata-${PORTVERSION}:${PORTSDIR}/games/naev-data

USE_AUTOTOOLS=	automake:111:env aclocal:111:env autoconf:268:env
USE_BZIP2=	yes
USE_DOS2UNIX=	conf.example
GNU_CONFIGURE=	yes
USE_GL=		gl
USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_SDL=	sdl image

CONFIGURE_ARGS=	--with-ndata-path=${DATADIR}/ndata-${PORTVERSION}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

MAN6=		naev.6
PLIST_FILES=	bin/${PORTNAME}
SUB_FILES=	pkg-message

OPTIONS=	OPENAL 		"Use the OpenAL sound backend"	on \
		SDL_MIXER	"Use the SDL_mixer sound backend"	on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not configure on 6.X
.endif

.if !defined(NOPORTDOCS)
PLIST_FILES+=	%%DOCSDIR%%/conf.example
PLIST_DIRS=	%%DOCSDIR%%
.endif

.if defined(WITH_OPENAL)
USE_OPENAL=		yes
CONFIGURE_ARGS+=	--with-openal=yes
.else
CONFIGURE_ARGS+=	--with-openal=no
.endif

.if defined(WITH_SDL_MIXER)
USE_SDL+=		mixer
CONFIGURE_ARGS+=	--with-sdlmixer=yes
.else
CONFIGURE_ARGS+=	--with-sdlmixer=no
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${PREFIX}/man/man6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/conf.example ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
