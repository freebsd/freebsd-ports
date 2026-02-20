PORTNAME=	openjazz
PORTVERSION=	20260218
CATEGORIES=	games

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Free re-implementation of the Jazz Jackrabbit(tm) game engine
WWW=		http://alister.eu/jazz/oj

LICENSE=	GPLv2

USES=	cmake dos2unix sdl xorg
USE_SDL=	sdl2
USE_XORG=	x11 xext xrandr xrender xau xdmcp

USE_GITHUB=	yes
GH_ACCOUNT=	AlisterT

CMAKE_ARGS+=	-DDATAPATH:PATH=${DATADIR} \
		-DSDL_VERSION:STRING=2

DOS2UNIX_REGEX=	.*\.(h|cpp)

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${TOUCH} ${STAGEDIR}${DATADIR}/.keepme
	${INSTALL_PROGRAM} ${CONFIGURE_WRKSRC}/OpenJazz ${STAGEDIR}${PREFIX}/bin/openjazz

.include <bsd.port.mk>
