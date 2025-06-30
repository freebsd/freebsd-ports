PORTNAME=	xmlcopyeditor
DISTVERSION=	1.3.1.0
PORTREVISION=	6
CATEGORIES=	editors
MASTER_SITES=	SF/xml-copy-editor/${PORTNAME}-linux/${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Fast validating XML editor
WWW=		http://xml-copy-editor.sourceforge.net/

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libaspell.so:textproc/aspell \
		libenchant-2.so:textproc/enchant2 \
		libexpat.so:textproc/expat2 \
		libharfbuzz.so:print/harfbuzz \
		libpcre2-8.so:devel/pcre2 \
		libxerces-c.so:textproc/xerces-c3 \
		libxslt.so:textproc/libxslt

USES=		autoreconf compiler:c++11-lang desktop-file-utils dos2unix \
		gettext-tools gmake gnome iconv libtool localbase pkgconfig
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 intltool libxml2 pango
USE_WX=		3.0 # fails to build with 3.2
WX_COMPS=	wx
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
