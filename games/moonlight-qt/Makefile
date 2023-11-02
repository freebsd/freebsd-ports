PORTNAME=	moonlight
DISTVERSION=	5.0.1
CATEGORIES=	games
MASTER_SITES=	https://github.com/moonlight-stream/moonlight-qt/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	-qt
DISTNAME=	MoonlightSrc-${DISTVERSIONFULL}

MAINTAINER=	lisp_25689@163.com
COMMENT=	Gamestream client
WWW=		https://github.com/moonlight-stream/moonlight-qt

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libopus.so:audio/opus \
		libva.so:multimedia/libva \
		libdrm.so:graphics/libdrm \
		libvdpau.so:multimedia/libvdpau \
		libwayland-client.so:graphics/wayland

USES=		desktop-file-utils gl localbase:ldflags pkgconfig \
		qmake:outsource qt:5 sdl ssl xorg
USE_QT=		core declarative gui network quickcontrols2 svg widgets buildtools:build
USE_GL=		egl
USE_SDL=	sdl2 ttf2
USE_XORG=	x11

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/moonlight-qt \
		share/applications/com.moonlight_stream.Moonlight.desktop \
		share/metainfo/com.moonlight_stream.Moonlight.appdata.xml \
		share/icons/hicolor/scalable/apps/moonlight.svg \

.include <bsd.port.pre.mk>

# fix ssl dependency lack on 12.x releases
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1300000
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB} -lssl -lcrypto
.endif

post-patch:
	@${REINPLACE_CMD} -e 's@Exec=moonlight.*@Exec=${PORTNAME}${PKGNAMESUFFIX}@' \
		${WRKSRC}/app/deploy/linux/com.moonlight_stream.Moonlight.desktop
	@${REINPLACE_CMD} -e 's@^    TARGET = moonlight.*@    TARGET = ${PORTNAME}${PKGNAMESUFFIX}@' \
		${WRKSRC}/app/app.pro

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1300000
	@${REINPLACE_CMD} -e 's@openssl @@' \
		${WRKSRC}/app/app.pro
	@${REINPLACE_CMD} -e '/openssl/ d' \
		${WRKSRC}/moonlight-common-c/moonlight-common-c.pro
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.post.mk>
