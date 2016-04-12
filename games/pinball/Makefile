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

USES=		gmake libtool:keepla # .la needed for plugin loading
USE_GL=		gl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} --without-debug

OPTIONS_DEFINE=	DOCS

.if defined(WITH_ALLEGRO)
BROKEN=		support with Allegro is (temporarily?) broken as of version 0.3.1
LIB_DEPENDS+=	liballeg.so:devel/allegro
CONFIGURE_ARGS+=	--with-allegro
USE_GL+=	glu
.else
USE_SDL=	image mixer sdl
.endif

CPPFLAGS+=	-I${LOCALBASE}/include -DRZR_LIBSTATIC
LDFLAGS+=	-L${LOCALBASE}/lib
#MAKE_JOBS_UNSAFE=	yes

DOCS=		README

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
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
