# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	pinball
PORTVERSION=	0.3.20201218
CATEGORIES=	games

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Emilia Pinball is a free pinball game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:devel/libltdl

USE_GITHUB=	yes
GH_ACCOUNT=	adoptware

USES=		autoreconf gl gmake localbase:ldflags libtool:keepla	\
		pkgconfig sdl xorg # .la needed for plugin loading
USE_XORG=	ice sm
USE_GL=		gl glu
USE_SDL=	image mixer sdl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-debug

CPPFLAGS+=	-DRZR_LIBSTATIC
SCOREDIR=	/var/games
PLIST_SUB=	SCOREDIR=${SCOREDIR}
#MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pinball/lib*.so*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
