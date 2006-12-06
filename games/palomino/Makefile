# New ports collection makefile for:	palomino
# Date created:		28 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	palomino
PORTVERSION=	20060827
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}-sim
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Action flight simulator with its own 3D engine

LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut

USE_ZIP=	yes
USE_PYTHON=	yes
USE_GL=		yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/${PORTNAME}/game/pony
MAKEFILE=	GNUmakefile
MAKE_ENV=	CC="${CC}" CXX="${CXX}"

post-patch:
	@${REINPLACE_CMD} -Ee 's!(string installDir = ).*$$!\1"${DATADIR}/";!' \
		-e 's!../game/!!' ${WRKSRC}/palomino/game/pony/src/game_pony_init.cc
	@${REINPLACE_CMD} -Ee 's!(CC_FLAGS.*:=)!\1 $$(CFLAGS)!' ${WRKSRC}/gfx/GNUmakefile_common
	@${REINPLACE_CMD} -Ee 's!(-O[0-9s]?|-funroll-loops|-fno-inline)!!g' ${WRKSRC}/gfx/tools/cc-config.sh
	@${REINPLACE_CMD} -e 's|-march=$$ARCH||' ${WRKSRC}/gfx/tools/cc-config.sh
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/gfx/tools/cc-config.sh

do-install:
	@${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/out/palomino ${PREFIX}/bin/
	@${INSTALL} -d ${DATADIR}/pony/out
	@${CP} -R ${INSTALL_WRKSRC}/models ${INSTALL_WRKSRC}/textures ${DATADIR}/pony/
	@${CHMOD} -R a+rX,u+w,go-w ${DATADIR}/pony
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/src/game_pony.py \
			${WRKSRC}/palomino/engine/src/eng.py ${DATADIR}/pony/out/

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	does not compile on 4.x
.endif

.include <bsd.port.post.mk>
