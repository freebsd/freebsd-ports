PORTNAME=	gtkspellmm
DISTVERSION=	3.0.5
CATEGORIES=	devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	gtkspell/${PORTNAME}
PKGNAMESUFFIX=	3

MAINTAINER=	me@svmhdvn.name
COMMENT=	Spellchecking for GtkText widgets
WWW=		https://gtkspell.sourceforge.net

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gmake gnome libtool pkgconfig tar:xz
USE_GNOME=	atk atkmm cairo cairomm gdkpixbuf glib20 glibmm gtk30 gtkmm30 \
		libsigc++20 pango pangomm

LIB_DEPENDS=	libgtkspell3-3.so:textproc/gtkspell3 \
		libenchant-2.so:textproc/enchant2

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
