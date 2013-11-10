# Created by: alepulver
# $FreeBSD$

PORTNAME=	sdlquake2
PORTVERSION=	0.1.4
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://koti.mbnet.fi/~turol/sdlquake2/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Combination of R1Q2 and R1GL with SDL code from Quake2Forge

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo

USE_BZIP2=	yes
USES=		gmake

OPTIONS_DEFINE=	CLIENT DEDICATED GAME
OPTIONS_DEFAULT=	CLIENT DEDICATED
CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server
GAME_DESC=	Build a main game .so file

OPTIONS_SUB=	yes

LIBDIR=		${PREFIX}/lib/${PORTNAME}
MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR=${LIBDIR:S/${PREFIX}\///}

.include "${.CURDIR}/../quake2-data/Makefile.include"

CLIENT_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
			libpng15.so:${PORTSDIR}/graphics/png
CLIENT_USE=		GL=yes
CLIENT_USE=		SDL=sdl
CLIENT_MAKE_ENV=	BUILD_CLIENT=YES
CLIENT_CFLAGS=		-I${LOCALBASE}/include/libpng15

DEDICATED_MAKE_ENV=	BUILD_DEDICATED=YES

GAME_MAKE_ENV=		BUILD_GAME=YES

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${LIBDIR}/baseq2
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2 ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/ref_sdlgl.so ${STAGEDIR}${LIBDIR}
.endif
.if ${PORT_OPTIONS:MDEDICATED}
	${INSTALL_PROGRAM} ${WRKSRC}/q2ded ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-ded
.endif
.if ${PORT_OPTIONS:MGAME}
	${INSTALL_PROGRAM} ${WRKSRC}/baseq2/game.so ${STAGEDIR}${LIBDIR}/baseq2
.endif

.include <bsd.port.mk>
