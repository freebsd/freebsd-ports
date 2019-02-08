# $FreeBSD$

PORTNAME=	xournalpp
DISTVERSION=	1.0.7-135
DISTVERSIONSUFFIX=	-g2f5b575e
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Handwriting notetaking software with PDF annotation support

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib \
		libportaudio.so:audio/portaudio \
		libsndfile.so:audio/libsndfile

USES=		cmake compiler:c++11-lang gettext-tools gnome pkgconfig
USE_GITHUB=	yes
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 libxml2 pango
USE_XORG=	x11 xi
USE_TEX=	latex

WITH_DEBUG=	1 # workaround for https://github.com/xournalpp/xournalpp/issues/844 (symbol not found)

# CAVEAT: crashes when built with gcc: https://github.com/xournalpp/xournalpp/issues/851

.include <bsd.port.mk>
