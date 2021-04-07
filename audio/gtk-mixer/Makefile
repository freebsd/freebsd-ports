PORTNAME=	gtk-mixer
PORTVERSION=	1.0.0
CATEGORIES=	audio

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	GTK based volume control tool

LICENSE=	GPLv2

USES=		cmake gnome pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_GITHUB=	yes
GH_ACCOUNT=	rozhuk-im

PLIST_FILES=	bin/gtk-mixer \
		share/pixmaps/gtk-mixer.png

DESKTOP_ENTRIES="GTK-Mixer" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "GTK;AudioVideo;Audio;Mixer;" true

post-install:
	${LN} -sf gvolwheel/audio-volume-high.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
