# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	f1spirit-remake
PORTVERSION=	1.0
PORTREVISION=	9
CATEGORIES=	games
# Original braingames site is really slow
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/ \
		http://www.braingames.getput.com/f1spirit/downloads/
DISTNAME=	f1spirit-linux

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Remake of classic F1 Spirit racing game

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USES=		dos2unix gmake zip
USE_SDL=	sdl net image mixer sound
USE_GL=		gl glu
DOS2UNIX_GLOB=	*.h *.cpp

WRKSRC=		"${WRKDIR}/F-1 Spirit"
BUILD_WRKSRC=	${WRKSRC}/sources

PLIST_FILES=	bin/f1s
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	@cd ${WRKSRC}/designs && ${RMDIR} endurance f3 f3000 # empty dirs

post-patch:
	@${FIND} ${BUILD_WRKSRC} -name '*.cpp' -print0 | ${XARGS} -0 ${REINPLACE_CMD} \
		-e 's|"demos"|"${DATADIR}/demos"|g; s|designs/|${DATADIR}/&|g; \
		s|f1spirit2.cfg|${DATADIR}/&|g; s|graphics/|${DATADIR}/&|g; \
		s|sound/|${DATADIR}/&|g; s|tracks/|${DATADIR}/&|g'
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' ${WRKSRC}/sources/F1Shttp.cpp

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/f1s ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} \
		'demos designs f1spirit2.cfg graphics sound tracks' \
		${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
