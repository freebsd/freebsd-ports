PORTNAME=	maolan
DISTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	meka@tilda.center
COMMENT=	Rust digital audio workstation
WWW=		https://maolan.github.io

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 powerpc64 powerpc64le

LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
		libjack.so:audio/jack \
		liblilv-0.so:audio/lilv \
		libonig.so:devel/oniguruma \
		librubberband.so:audio/rubberband \
		libsentencepiece.so:textproc/sentencepiece \
		libsuil-0.so:audio/suil

USES=		cargo gnome llvm:build pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	maolan
GH_TAGNAME=	${DISTVERSION}

USE_GNOME=	glib20 gtk20
USE_XORG=	x11

MAKE_ENV=	LIBCLANG_PATH="${LOCALBASE}/llvm${LLVM_VERSION}/lib"

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/desktop/maolan-bsd.desktop \
		${STAGEDIR}${PREFIX}/share/applications/maolan.desktop
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/images/maolan.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include <bsd.port.mk>
