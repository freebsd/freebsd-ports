PORTNAME=	pa-applet
PORTVERSION=	g20181009
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	glowiak1111@yandex.com
COMMENT=	PulseAudio system tray applet with volume bar
WWW=		https://github.com/fernandotcl/pa-applet

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
		libnotify.so:devel/libnotify

USES=		autoreconf gnome pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	fernandotcl
GH_TAGNAME=	3b4f8b3

DESKTOP_ENTRIES=	"PulseAudio Applet" "${COMMENT}" \
			"audio-volume-high" "${PORTNAME}" \
			"GNOME;GTK;System;" true

PLIST_FILES=	bin/pa-applet man/man1/pa-applet.1.gz

.include <bsd.port.mk>
