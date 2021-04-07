PORTNAME=	stransball2
PORTVERSION=	1.5
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/ \
		http://braingames.bugreport.nl/stransball2/
DISTNAME=	${PORTNAME}-v${PORTVERSION:C/\.//}-linux

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Sequel to Transball and Transball 2 THRUST-type games

LICENSE=	GPLv2
LICENSE_FILE=	${BUILD_WRKSRC}/LICENSE

LIB_DEPENDS=	libSGE.so:devel/sdl_sge

USES=		dos2unix gmake sdl zip
DOS2UNIX_FILES=	sources/main.cpp sources/auxiliar.cpp
USE_SDL=	sdl image mixer sound

BUILD_WRKSRC=	${WRKSRC}/sources

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} ${WRKSRC}/sound/WS_FTP.LOG

post-patch:
	@${FIND} ${BUILD_WRKSRC} -name '*.cpp' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|demos/|${DATADIR}/&|g; s|graphics/|${DATADIR}/&|g; \
		s|maps/|${DATADIR}/&|g; s|sound/|${DATADIR}/&|g; \
		s|"maps"|"${DATADIR}/maps"|g'

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@cd ${WRKSRC} && ${COPYTREE_SHARE} 'graphics sound maps demos' ${STAGEDIR}${DATADIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
