# Created by: Ulrich Spoerlein <uspoerlein@gmail.com>
# $FreeBSD$

PORTNAME=	librcc
PORTVERSION=	0.2.9
PORTREVISION=	6
CATEGORIES=	devel
#MASTER_SITES=	SF/rusxmms/Charset%20Conversion%20Library/${PORTVERSION} \
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://ns.ael.ru/~fluffy.khv/distfiles/ \
		http://dside.dyndns.org/files/rusxmms/
MASTER_SITE_SUBDIR=	fluffy

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Library used by rusxmms for language autodetection

LIB_DEPENDS=	rcd.1:${PORTSDIR}/devel/librcd \
		enca.5:${PORTSDIR}/converters/enca \
		aspell.16:${PORTSDIR}/textproc/aspell

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	lthack libxml2
USES=		gmake iconv pathfix pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoheader

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS=		-L${LOCALBASE}/lib

CONFIGURE_ENV=	LIBS="${LIBS}"

OPTIONS_DEFINE=	BDB TRANSLATE TOOLS GTK1 GTK2
BDB_DESC=	Translation database support
TRANSLATE_DESC=	Online translation support
TOOLS_DESC=	Recode configuration utility

OPTIONS_DEFAULT=	TOOLS GTK1 GTK2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBDB}
USE_BDB=	41+
CPPFLAGS+=	-I${BDB_INCLUDE_DIR}
LIBS+=		-L${BDB_LIB_DIR}
CONFIGURE_ARGS+=--enable-bdb
.else
CONFIGURE_ARGS+=--disable-bdb
.endif

.if ${PORT_OPTIONS:MTRANSLATE}
LIB_DEPENDS+=	translate.0:${PORTSDIR}/textproc/libtranslate
CONFIGURE_ARGS+=--enable-libtranslate
.else
CONFIGURE_ARGS+=--disable-libtranslate
.endif

.if ${PORT_OPTIONS:MGTK1}
USE_GNOME+=	glib12 gtk12
PLIST_SUB+=	WITH_GTK1=""
.else
CONFIGURE_ENV+=	ac_cv_path_GTK_CONFIG=no GTK_CONFIG=no
PLIST_SUB+=	WITH_GTK1="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
PLIST_SUB+=	WITH_GTK2=""
.else
CONFIGURE_ARGS+=--disable-glib2 --disable-gtk2
PLIST_SUB+=	WITH_GTK2="@comment "
.endif

.if ${PORT_OPTIONS:MTOOLS}
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-rcc-config
PLIST_SUB+=	TOOLS=""
.else
PLIST_SUB+=	TOOLS="@comment "
.endif

pre-everything::
.if ${ARCH} == "i386"
.if ${PORT_OPTIONS:MBDB} || ${PORT_OPTIONS:MTRANSLATE}
	@${ECHO} 'BDB/LibTranslate support may cause breakages in depended apps on ${ARCH}'
	@${ECHO} 'Use it with caution'
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/external/rccexternal.c

.include <bsd.port.mk>
