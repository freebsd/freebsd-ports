# $FreeBSD$

PORTNAME=	xdemorse
DISTVERSION=	3.6.2
CATEGORIES=	comms
MASTER_SITES=	https://www.qsl.net/5/5b4az/pkg/morse/xdemorse/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	X/GTK+-3 application for decoding Morse code signals into text

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		gettext-tools gmake gnome localbase:ldflags pkgconfig tar:bz2
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30

LDFLAGS+=	-lgmodule-2.0

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
