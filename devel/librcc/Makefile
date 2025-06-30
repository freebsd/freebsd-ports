PORTNAME=	librcc
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	0.2.13
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library used by rusxmms for language autodetection
WWW=		https://rusxmms.sourceforge.net

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librcd.so:devel/librcd \
		libenca.so:converters/enca \
		libaspell.so:textproc/aspell

USES=		autoreconf compiler:c++11-lang gmake gnome iconv libtool \
		localbase:ldflags pathfix pkgconfig
USE_GITHUB=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

GH_ACCOUNT=	RusXMMS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk1

OPTIONS_DEFINE=	BDB TRANSLATE TOOLS GTK2 GTK3
OPTIONS_DEFAULT=TOOLS GTK3
OPTIONS_SUB=	yes

BDB_DESC=		Translation database support
BDB_CONFIGURE_ENABLE=	bdb
BDB_CPPFLAGS=		-I${BDB_INCLUDE_DIR}
BDB_LDFLAGS=		-L${BDB_LIB_DIR}
BDB_USES=		bdb

TRANSLATE_DESC=			Online translation support
TRANSLATE_CONFIGURE_ENABLE=	libtranslate
TRANSLATE_LIB_DEPENDS=		libtranslate.so:textproc/libtranslate

TOOLS_DESC=		Recode configuration utility
TOOLS_EXTRA_PATCHES=	${FILESDIR}/extrapatch-rcc-config

GTK2_CONFIGURE_ENABLE=	gtk2
GTK2_USE=		GNOME=gtk20

GTK3_CONFIGURE_ENABLE=	gtk3
GTK3_USE=		GNOME=gtk30

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ARGS+=--enable-force-system-iconv
.endif

.if ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MGTK3}
CONFIGURE_ARGS+=--enable-glib2
PLIST_SUB+=	WITH_GLIB2=""
.else
CONFIGURE_ARGS+=--disable-glib2
PLIST_SUB+=	WITH_GLIB2="@comment "
.endif

pre-everything::
.if ${ARCH} == "i386"
.if ${PORT_OPTIONS:MBDB} || ${PORT_OPTIONS:MTRANSLATE}
	@${ECHO} 'BDB/LibTranslate support may cause breakages in depended apps on ${ARCH}'
	@${ECHO} 'Use it with caution'
.endif
.endif

.include <bsd.port.post.mk>
