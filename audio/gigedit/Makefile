PORTNAME=	gigedit
DISTVERSION=	1.2.1
CATEGORIES=	audio
MASTER_SITES=	http://download.linuxsampler.org/packages/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical instrument editor for sample based virtual instruments
WWW=		https://edrums.github.io/en/linuxsampler/docs/gigedit/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgig.so:audio/libgig \
		libharfbuzz.so:print/harfbuzz \
		liblinuxsampler.so:audio/linuxsampler \
		libsndfile.so:audio/libsndfile

USES=		autoreconf gettext gmake gnome libtool pkgconfig tar:bz2
USE_GNOME=	cairo cairomm gdkpixbuf2 glib20 glibmm gtk30 gtkmm30 intltool pango pangomm
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

LDFLAGS+=	-pthread

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
