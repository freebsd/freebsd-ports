PORTNAME=	xournalpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.8
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Handwriting notetaking software with PDF annotation support
WWW=		https://github.com/xournalpp/xournalpp

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails: error: redefinition of 'getGVariantValue<unsigned int>': see https://github.com/xournalpp/xournalpp/issues/5873
BROKEN_i386=	compilation fails: error: redefinition of 'getGVariantValue<unsigned int>': see https://github.com/xournalpp/xournalpp/issues/5873
BROKEN_powerpc=	compilation fails: error: redefinition of 'getGVariantValue<unsigned int>': see https://github.com/xournalpp/xournalpp/issues/5873

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libgtksourceview-4.so:x11-toolkits/gtksourceview4 \
		libharfbuzz.so:print/harfbuzz \
		libpoppler-glib.so:graphics/poppler-glib \
		libportaudio.so:audio/portaudio \
		libsndfile.so:audio/libsndfile \
		libzip.so:archivers/libzip

USES=		cmake compiler:c++11-lang gettext-tools gnome lua pkgconfig tex xorg desktop-file-utils shared-mime-info
USE_GITHUB=	yes
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 librsvg2 libxml2 pango
USE_XORG=	x11 xext xi
USE_TEX=	latex:build

LDFLAGS+=	-lexecinfo

# CAVEAT: crashes when built with gcc: https://github.com/xournalpp/xournalpp/issues/851

.include <bsd.port.mk>
