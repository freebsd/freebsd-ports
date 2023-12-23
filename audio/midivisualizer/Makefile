PORTNAME=	midivisualizer
DISTVERSIONPREFIX=	v
DISTVERSION=	7.2
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Small MIDI visualizer tool, using OpenGL
WWW=		https://github.com/kosua20/MIDIVisualizer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libatk-1.0.so:accessibility/at-spi2-core \
		libavcodec.so:multimedia/ffmpeg \
		libharfbuzz.so:print/harfbuzz \
		libjack.so:audio/jack \
		libnotify.so:devel/libnotify

USES=		cmake compiler:c++20-lang gettext-runtime gl gnome localbase:ldflags pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 pango
USE_GL=		gl
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	kosua20
GH_PROJECT=	MIDIVisualizer

PLIST_FILES=	bin/MIDIVisualizer

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/MIDIVisualizer ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
