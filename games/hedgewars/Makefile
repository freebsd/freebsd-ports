# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hedgewars
DISTVERSION=	0.9.18-3
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/hedgewars/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-src-${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Worms-like turn based strategy game

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	depends on fpc which is only available for i386 and amd64

USE_BZIP2=	yes
USES=		cmake
USE_SDL=	sdl mixer image ttf net
USE_FPC=	opengl libpng
USE_LUA=	5.1+
USE_QT4=	corelib gui moc_build network \
		qmake_build rcc_build svg xml \
		uic_build linguist_build
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:C/-[0-9]$//}

PLIST_FILES=	bin/hedgewars bin/hwengine \
		share/applications/hedgewars.desktop \
		share/pixmaps/hedgewars.png
PLIST_DIRSTRY=	share/applications
PORTDATA=	*

post-patch:
	@${ECHO} "include_directories(${LOCALBASE}/include)" >> \
		${WRKSRC}/QTfrontend/CMakeLists.txt
.if defined(NOPORTDATA)
	@${REINPLACE_CMD} -e '/add_subdirectory.*Data/I d' \
		${WRKSRC}/share/hedgewars/CMakeLists.txt
.endif

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/misc/hedgewars.desktop \
		${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/misc/hedgewars.png \
		${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
