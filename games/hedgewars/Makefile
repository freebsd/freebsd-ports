# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hedgewars
PORTVERSION=	0.9.20.5
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/hedgewars/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-src-${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Worms-like turn based strategy game

LICENSE=	GPLv2 GFDL
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	depends on fpc which is only available for i386 and amd64

USES=		tar:bzip2 cmake lua:51
USE_SDL=	sdl mixer image ttf net
USE_FPC=	opengl libpng
USE_QT4=	corelib gui moc_build network \
		qmake_build rcc_build svg xml \
		uic_build linguist_build
CMAKE_ARGS=	-DNOVIDEOREC=1
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:C/\.[0-9]$//}

PLIST_FILES=	bin/${PORTNAME} bin/hwengine \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png \
		lib/libhwphysfs.so \
		lib/libhwphysfs.so.1 \
		lib/libhwphysfs.so.2.1.0 \
		lib/libphyslayer.so
PORTDATA=	*

# VIDEOREC - broken with recent ffmpeg
OPTIONS_DEFINE=	SERVER # VIDEOREC
OPTIONS_DEFAULT=SERVER

SERVER_DESC=	Build server (requires haskell)
#VIDEOREC_DESC=	Enable video recording (requires ffmpeg)

#VIDEOREC_LIB_DEPENDS=libavcodec0.so:${PORTSDIR}/multimedia/ffmpeg0
#VIDEOREC_CMAKE_OFF=-DNOVIDEOREC=1

SERVER_BUILD_DEPENDS=\
		ghc:${PORTSDIR}/lang/ghc \
		hs-vector>=0:${PORTSDIR}/devel/hs-vector \
		hs-network>=0:${PORTSDIR}/net/hs-network \
		hs-utf8-string>=0:${PORTSDIR}/devel/hs-utf8-string \
		hs-bytestring-show>=0:${PORTSDIR}/devel/hs-bytestring-show \
		hs-dataenc>=0:${PORTSDIR}/converters/hs-dataenc \
		hs-random>=0:${PORTSDIR}/devel/hs-random \
		hs-hslogger>=0:${PORTSDIR}/devel/hs-hslogger
SERVER_CMAKE_OFF=-DNOSERVER=1
SERVER_PLIST_FILES=bin/${PORTNAME}-server

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/cmake_modules/*.cmake

post-install:
	${INSTALL_DATA} ${WRKSRC}/share/hedgewars/Data/misc/hedgewars.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/misc/hedgewars.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
