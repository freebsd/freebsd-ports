PORTNAME=	xournalpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Handwriting notetaking software with PDF annotation support

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libpoppler-glib.so:graphics/poppler-glib \
		libportaudio.so:audio/portaudio \
		libsndfile.so:audio/libsndfile \
		libzip.so:archivers/libzip

USES=		cmake compiler:c++11-lang gettext-tools gnome lua:53 pkgconfig xorg
USE_GITHUB=	yes
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 librsvg2 libxml2 pango
USE_XORG=	x11 xi
USE_TEX=	latex

LDFLAGS+=	-lexecinfo

# CAVEAT: crashes when built with gcc: https://github.com/xournalpp/xournalpp/issues/851

.include <bsd.port.mk>
