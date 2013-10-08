# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cuberok
PORTVERSION=	0.0.11
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	vg@FreeBSD.org
COMMENT=	A music player and a collection manager based on Qt4

BUILD_DEPENDS=	audiere-config:${PORTSDIR}/audio/audiere \
		${LOCALBASE}/lib/libdumb.a:${PORTSDIR}/audio/dumb
LIB_DEPENDS=	libavcodec0.so:${PORTSDIR}/multimedia/ffmpeg0 \
		libavformat0.so:${PORTSDIR}/multimedia/ffmpeg0 \
		libavutil0.so:${PORTSDIR}/multimedia/ffmpeg0 \
		libtag.so:${PORTSDIR}/audio/taglib

USE_LDCONFIG=	yes
USE_QT4=	gui xml qmake_build uic_build moc_build rcc_build \
		network phonon-gst sql
USES=		gettext iconv pkgconfig
NO_STAGE=	yes
USE_SDL=	sdl
QMAKEFLAGS+=	"CONFIG+=player_phonon"
MAKE_ENV+=	INSTALL_ROOT=${PREFIX}
QMAKEPRO=	Cuberok.pro

post-patch:
	@${REINPLACE_CMD} \
		-e 's,libavcodec,libavcodec0,g' \
		-e 's,libavutil,libavutil0,g' \
		-e 's,libavformat,libavformat0,g' \
		${WRKSRC}/Cuberok.pro \
		${WRKSRC}/plugins/player_ffmpeg/player_ffmpeg.pro

do-configure:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's/lib64/lib/g' \
		plugins/plugins_path-x86*

	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.include <bsd.port.post.mk>
