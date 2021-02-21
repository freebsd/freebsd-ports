# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gvolwheel
PORTVERSION=	1.0.3
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Control volume by scrolling over tray icon

LICENSE=	GPLv3

USES=		autoreconf libtool gmake gnome pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-oss
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_GITHUB=	yes
GH_ACCOUNT=	Junker

PORTDOCS=	AUTHORS ChangeLog README.md

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

DESKTOP_ENTRIES="GVolWheel" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "GTK;AudioVideo;Audio;Mixer;" true

post-install:
	${LN} -sf gvolwheel/audio-volume-high.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
