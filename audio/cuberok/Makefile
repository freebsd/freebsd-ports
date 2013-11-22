# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cuberok
PORTVERSION=	0.0.11
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Music player and collection manager based on Qt4

BUILD_DEPENDS=	audiere-config:${PORTSDIR}/audio/audiere \
		${LOCALBASE}/lib/libdumb.a:${PORTSDIR}/audio/dumb
LIB_DEPENDS=	libavcodec0.so:${PORTSDIR}/multimedia/ffmpeg0 \
		libavformat0.so:${PORTSDIR}/multimedia/ffmpeg0 \
		libavutil0.so:${PORTSDIR}/multimedia/ffmpeg0 \
		libtag.so:${PORTSDIR}/audio/taglib

USE_LDCONFIG=	yes
USE_QT4=	gui xml uic_build moc_build rcc_build \
		network phonon-gst sql
USES=		gettext iconv pkgconfig qmake
USE_SDL=	sdl
QMAKE_ARGS+=	"CONFIG+=player_phonon"

BROKEN_ia64=	does not compile
BROKEN_powerpc=	${BROKEN_ia64}
BROKEN_sparc64=	${BROKEN_ia64}

post-patch:
	@${REINPLACE_CMD} \
		-e 's,libavcodec,libavcodec0,g' \
		-e 's,libavutil,libavutil0,g' \
		-e 's,libavformat,libavformat0,g' \
		${WRKSRC}/Cuberok.pro \
		${WRKSRC}/plugins/player_ffmpeg/player_ffmpeg.pro
	${REINPLACE_CMD} -e 's/lib64/lib/g' \
		${WRKSRC}/plugins/plugins_path-x86*
# Fix installation paths
	${REINPLACE_CMD} '/.path =/s,= \(.*\),= $$$$PREFIX/\1,' \
			${WRKSRC}/plugins/*.pri \
			${WRKSRC}/src/src.pro

.include <bsd.port.mk>
