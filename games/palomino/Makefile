# New ports collection makefile for:	palomodulesmemino
# Date created:		28 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	palomino
PORTVERSION=	20061125
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}-sim
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Action flight simulator with its own 3D engine

USE_ZIP=	yes
USE_PYTHON=	yes
USE_GL=		glut
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/${PORTNAME}/modules/pony
MAKEFILE=	GNUmakefile

post-patch:
	@${REINPLACE_CMD} -e '/APPLE_CC/s|$$| \&\& !defined(__FreeBSD__)|'\
		${WRKSRC}/gfx/src/gfx_math.hh
	@${REINPLACE_CMD} -Ee 's|(string (unix)?[iI]nstallDir = ).*$$|\1"${DATADIR}/";|'\
		-e 's!../modules/!!' ${WRKSRC}/palomino/modules/pony/src/mod_pony_init.cc
	@${REINPLACE_CMD} -Ee 's|(CC_FLAGS.*:=)|\1 $$(CFLAGS)|' ${WRKSRC}/gfx/GNUmakefile_common
	@${REINPLACE_CMD} -Ee 's!(-O[0-9s]?|-funroll-loops|-fno-inline)!!g'\
		${WRKSRC}/gfx/tools/cc-config.sh
	@${REINPLACE_CMD} -e 's|-march=$$ARCH||' ${WRKSRC}/gfx/tools/cc-config.sh
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g'\
		${WRKSRC}/gfx/tools/cc-config.sh ${WRKSRC}/gfx/tools/ld-config.sh

do-install:
	@${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/out/palomino ${PREFIX}/bin/
	@${INSTALL} -d ${DATADIR}/pony/out/
	@${CP} -R ${INSTALL_WRKSRC}/models ${INSTALL_WRKSRC}/textures ${DATADIR}/pony/
	@${CHMOD} -R a+rX,u+w,go-w ${DATADIR}/pony/
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/src/mod_pony.py \
			${WRKSRC}/palomino/engine/src/eng.py ${DATADIR}/pony/out/

.include <bsd.port.mk>
