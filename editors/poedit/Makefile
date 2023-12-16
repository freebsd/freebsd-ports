PORTNAME=	poedit
PORTVERSION=	3.3.1
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	https://github.com/vslavik/${PORTNAME}/releases/download/v${PORTVERSION}-oss/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Gettext catalogs (.po files) editor
WWW=		https://www.poedit.net/

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libgtkspell3-3.so:textproc/gtkspell3 \
		libboost_thread.so:devel/boost-libs \
		libicui18n.so:devel/icu \
		liblucene++.so:textproc/luceneplusplus \
		libenchant-2.so:textproc/enchant2 \
		libharfbuzz.so:print/harfbuzz

USES=		bdb compiler:c++11-lib desktop-file-utils gmake gnome \
		pkgconfig
WITH_BDB_HIGHEST=	yes
USE_GNOME+=	gtk30 pango cairo gdkpixbuf2 glib20
USE_WX=		3.0
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WXRC="${WXRC_CMD}"

CPPFLAGS+=	-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include
## -stdlib=libc++
LDFLAGS+=	-lpthread -L${BDB_LIB_DIR} -L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
