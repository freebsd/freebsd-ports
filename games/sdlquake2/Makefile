# New ports collection makefile for:	sdlquake2
# Date created:				5 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	sdlquake2
PORTVERSION=	0.1.4
CATEGORIES=	games
MASTER_SITES=	http://koti.mbnet.fi/~turol/sdlquake2/

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Combination of R1Q2 and R1GL with SDL code from Quake2Forge

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GCC=	3.2+
USE_GMAKE=	yes
USE_GL=		yes
USE_SDL=	sdl

MAKE_ENV=	LIBDIR="${LIBDIR}"

LIBDIR=		${PREFIX}/lib/${PORTNAME}
PLIST_SUB=	LIBDIR=${LIBDIR:S/${PREFIX}\///}

do-install:
	${MKDIR} ${LIBDIR}/baseq2
	${INSTALL_PROGRAM} ${WRKSRC}/ref_sdlgl.so ${LIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/baseq2/game.so ${LIBDIR}/baseq2
	${INSTALL_PROGRAM} ${WRKSRC}/quake2 ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/q2ded ${PREFIX}/bin/${PORTNAME}-ded

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.mk>
