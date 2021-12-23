PORTNAME=	gtk-mixer
DISTVERSION=	1.0.2
CATEGORIES=	audio

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	GTK based volume control tool

LICENSE=	GPLv2

USES=		cmake gnome pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_GITHUB=	yes
GH_ACCOUNT=	rozhuk-im

PLIST_FILES=	bin/gtk-mixer

DESKTOP_ENTRIES="GTK-Mixer" "${COMMENT}" "multimedia-volume-control" \
		"${PORTNAME}" "GTK;AudioVideo;Audio;Mixer;" true

.include <bsd.port.mk>
