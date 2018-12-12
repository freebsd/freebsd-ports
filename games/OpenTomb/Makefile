# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	OpenTomb
DISTVERSIONPREFIX=	win32-
DISTVERSION=	2018-02-03_alpha
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Open-source Tomb Raider 1-5 engine remake

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake compiler:c++11-lang lua openal
USE_GITHUB=	yes
USE_SDL=	sdl2
LLD_UNSAFE=	yes
SUB_FILES=	OpenTomb

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/render/shader_manager.cpp
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/scripts/entity/entity_functions.lua
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/scripts/trigger/trigger_functions.lua

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/autoexec.lua ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/scripts && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/scripts "! -name *\.bak"
	@cd ${WRKSRC}/shaders && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/shaders
	@cd ${WRKSRC}/resource && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/resource
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
