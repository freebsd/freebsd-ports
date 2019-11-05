# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	pinball
PORTVERSION=	0.3.4
CATEGORIES=	games

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Emilia Pinball is a free pinball game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:devel/libltdl

USE_GITHUB=	yes
GH_ACCOUNT=	sergiomb2

USES=		autoreconf gl gettext gmake localbase:ldflags libtool:keepla sdl xorg # .la needed for plugin loading
USES+=		sdl
USE_XORG=	ice sm
USE_GL=		gl glu
USE_SDL=	image mixer sdl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-debug

CPPFLAGS+=	-DRZR_LIBSTATIC
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS

post-install.orig:
	${MV} ${STAGEDIR}/var/games/pinball/professor/highscores \
		${STAGEDIR}/var/games/pinball/professor/highscores.sample
	${MV} ${STAGEDIR}/var/games/pinball/tux/highscores \
		${STAGEDIR}/var/games/pinball/tux/highscores.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pinball/lib*.so*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
