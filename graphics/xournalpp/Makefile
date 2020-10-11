# $FreeBSD$

PORTNAME=	xournalpp
DISTVERSION=	1.0.18.20200927
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Handwriting notetaking software with PDF annotation support

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib \
		libportaudio.so:audio/portaudio \
		libsndfile.so:audio/libsndfile \
		libzip.so:archivers/libzip

USES=		cmake compiler:c++11-lang gettext-tools gnome pkgconfig xorg
USE_GITHUB=	yes
GH_TAGNAME=	307d67f02d00c7c9305cc609736d49e2f54961d3
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 libxml2 pango
USE_XORG=	x11 xi
USE_TEX=	latex

# CAVEAT: crashes when built with gcc: https://github.com/xournalpp/xournalpp/issues/851

.include <bsd.port.mk>
