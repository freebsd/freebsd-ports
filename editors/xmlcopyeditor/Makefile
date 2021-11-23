PORTNAME=	xmlcopyeditor
PORTVERSION=	1.3.0.0
CATEGORIES=	editors
MASTER_SITES=	SF/xml-copy-editor/${PORTNAME}-linux/${PORTVERSION}

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Fast validating XML editor

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libaspell.so:textproc/aspell \
		libenchant.so:textproc/enchant \
		libexpat.so:textproc/expat2 \
		libharfbuzz.so:print/harfbuzz \
		libpcre.so:devel/pcre \
		libxerces-c.so.3:textproc/xerces-c3 \
		libxml2.so:textproc/libxml2 \
		libxslt.so:textproc/libxslt

USES=		autoreconf compiler:c++11-lang desktop-file-utils dos2unix \
		gmake gettext-tools gnome iconv libtool pkgconfig
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 intltool pango
USE_WX=		3.0+
WX_COMPS=	wx
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls # NLS does not work properly

CPPFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
