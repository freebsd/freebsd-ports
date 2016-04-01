# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pink-pony
PORTVERSION=	1.3.1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tron-like multiplayer racing game

LICENSE=	GPLv3

LIB_DEPENDS=	libIL.so:graphics/devil \
		libprotobuf.so:devel/protobuf \
		libglfw.so:graphics/glfw2 \
		libHalf.so:graphics/ilmbase \
		libftgl.so:graphics/ftgl \
		libsigc-2.0.so:devel/libsigc++20

USES=		dos2unix pkgconfig scons tar:bzip2
USE_GL=		gl glu
USE_SDL=	mixer
SUB_FILES=	pink-pony.sh
DOS2UNIX_FILES=	lib/GL/GLee.h

PORTDOCS=	*
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -Ee 's,resources/,${DATADIR}/,' \
		${WRKSRC}/pony.options ${WRKSRC}/lib/Config.cc
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/install/pink-pony.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Pony ${STAGEDIR}${PREFIX}/libexec/
	cd ${WRKSRC}/resources && ${COPYTREE_SHARE} '*' ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/pony.options ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/pink-pony.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/install/pink-pony.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/install/pink-pony.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
