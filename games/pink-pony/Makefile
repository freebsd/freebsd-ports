# New ports collection makefile for:	pink-pony
# Date created:		07 Jul 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pink-pony
PORTVERSION=	1.2.1
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tron-like multiplayer racing game

LIB_DEPENDS=	IL.2:${PORTSDIR}/graphics/devil \
		protobuf.4:${PORTSDIR}/devel/protobuf \
		glfw.0:${PORTSDIR}/graphics/glfw \
		Half.6:${PORTSDIR}/graphics/ilmbase \
		ftgl.2:${PORTSDIR}/graphics/ftgl \
		sigc-2.0.0:${PORTSDIR}/devel/libsigc++20
BUILD_DEPENDS=	${LOCALBASE}/lib/libaudiere.so:${PORTSDIR}/audio/audiere
RUN_DEPENDS=	${LOCALBASE}/lib/libaudiere.so:${PORTSDIR}/audio/audiere

USE_BZIP2=	yes
USE_SCONS=	yes
USE_GL=		gl glu
MAKE_JOBS_SAFE=	yes
SUB_FILES=	pink-pony.sh

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	README

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
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/install/pink-pony.desktop ${PREFIX}/share/applications/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
