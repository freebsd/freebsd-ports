# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pink-pony
PORTVERSION=	1.2.1
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tron-like multiplayer racing game

LIB_DEPENDS=	IL:${PORTSDIR}/graphics/devil \
		protobuf:${PORTSDIR}/devel/protobuf \
		glfw:${PORTSDIR}/graphics/glfw \
		Half:${PORTSDIR}/graphics/ilmbase \
		ftgl:${PORTSDIR}/graphics/ftgl \
		sigc-2.0:${PORTSDIR}/devel/libsigc++20
BUILD_DEPENDS=	${LOCALBASE}/lib/libaudiere.so:${PORTSDIR}/audio/audiere
RUN_DEPENDS=	${LOCALBASE}/lib/libaudiere.so:${PORTSDIR}/audio/audiere

USES=		pkgconfig
USE_BZIP2=	yes
USE_SCONS=	yes
USE_GL=		gl glu
SUB_FILES=	pink-pony.sh
USE_DOS2UNIX=	lib/GL/GLee.h

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	README

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -Ee 's,(GLSL|levels|models|music|textures|fonts)/,${DATADIR}/&,' \
		${WRKSRC}/pony.options ${WRKSRC}/Pony.cc ${WRKSRC}/lib/*.cc ${WRKSRC}/levels.xml
	@${REINPLACE_CMD} -e 's|levels.xml|${DATADIR}/&|' \
		${WRKSRC}/lib/Config.cc ${WRKSRC}/pony.options
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/install/pink-pony.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Pony ${PREFIX}/libexec/
	cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"GLSL levels* models music textures fonts pony.options" ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/pink-pony.sh ${PREFIX}/bin/pink-pony
	${INSTALL_DATA} ${WRKSRC}/install/pink-pony.png ${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/install/pink-pony.desktop ${PREFIX}/share/applications/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
