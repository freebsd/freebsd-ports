# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hedgewars
PORTVERSION=	0.9.19.3
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

WRKSRC=		${WRKDIR}/${DISTNAME:C/-[0-9]$//}

PLIST_FILES=	bin/hedgewars bin/hwengine \
		share/applications/hedgewars.desktop \
		share/pixmaps/hedgewars.png
PORTDATA=	*

OPTIONS_DEFINE=	VIDEOREC SERVER
OPTIONS_DEFAULT=VIDEOREC SERVER
VIDEOREC_DESC=	Enable video recording (requires ffmpeg)
SERVER_DESC=	Build server (requires haskell)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVIDEOREC}
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
.else
CMAKE_ARGS+=	-DNOVIDEOREC=1
.endif

.if ${PORT_OPTIONS:MSERVER}
BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-vector>=0:${PORTSDIR}/devel/hs-vector \
		hs-network>=0:${PORTSDIR}/net/hs-network \
		hs-utf8-string>=0:${PORTSDIR}/devel/hs-utf8-string \
		hs-bytestring-show>=0:${PORTSDIR}/devel/hs-bytestring-show \
		hs-dataenc>=0:${PORTSDIR}/converters/hs-dataenc \
		hs-random>=0:${PORTSDIR}/devel/hs-random \
		hs-hslogger>=0:${PORTSDIR}/devel/hs-hslogger
PLIST_FILES+=	bin/hedgewars-server
.else
CMAKE_ARGS+=	-DNOSERVER=1
.endif

post-patch:
.if defined(NOPORTDATA)
	@${REINPLACE_CMD} -e '/add_subdirectory.*Data/I d' \
		${WRKSRC}/share/hedgewars/CMakeLists.txt
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/share/hedgewars/Data/misc/hedgewars.desktop \
		${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/misc/hedgewars.png \
		${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
