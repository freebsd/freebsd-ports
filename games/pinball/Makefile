# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	pinball
PORTVERSION=	0.3.1
PORTREVISION=	20
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Emilia Pinball is a free pinball game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake localbase:ldflags libtool:keepla # .la needed for plugin loading
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-debug
USE_LDCONFIG=	yes

CPPFLAGS+=	-DRZR_LIBSTATIC

OPTIONS_DEFINE=	DOCS

.if defined(WITH_ALLEGRO)
BROKEN=		support with Allegro is (temporarily?) broken as of version 0.3.1
LIB_DEPENDS+=	liballeg.so:devel/allegro
CONFIGURE_ARGS+=	--with-allegro
USE_GL+=	glu
.else
USE_SDL=	image mixer sdl
.endif
#MAKE_JOBS_UNSAFE=	yes

# For gmake>=3.82
pre-configure:
	@${FIND} ${WRKSRC} -name Makefile.in -print | ${XARGS} \
		${REINPLACE_CMD} -e 's,^dnl,# dnl,'

post-install:
	@${MV} ${STAGEDIR}/var/games/pinball/professor/highscores \
		${STAGEDIR}/var/games/pinball/professor/highscores.sample
	@${MV} ${STAGEDIR}/var/games/pinball/tux/highscores \
		${STAGEDIR}/var/games/pinball/tux/highscores.sample
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pinball/lib*.so*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
