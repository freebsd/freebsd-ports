# $FreeBSD$

PORTNAME=	xournalpp
DISTVERSION=	1.0.18.20200921
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Handwriting notetaking software with PDF annotation support

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	non-constant-expression cannot be narrowed from type 'unsigned long long' to 'size_t' (aka 'unsigned int') in initializer list: https://github.com/xournalpp/xournalpp/issues/2267

LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib \
		libportaudio.so:audio/portaudio \
		libsndfile.so:audio/libsndfile \
		libzip.so:archivers/libzip

USES=		cmake compiler:c++11-lang gettext-tools gnome pkgconfig xorg
USE_GITHUB=	yes
GH_TAGNAME=	03963b53944329a3d26d9a8d6f0c111949aa717f
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 libxml2 pango
USE_XORG=	x11 xi
USE_TEX=	latex

# CAVEAT: crashes when built with gcc: https://github.com/xournalpp/xournalpp/issues/851

.include <bsd.port.mk>
