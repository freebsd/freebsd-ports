# New ports collection makefile for:	librcc
# Date created:			30-12-2007
# Whom:				Ulrich Spoerlein <uspoerlein@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	librcc
PORTVERSION=	0.2.9
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF/rusxmms/Charset%20Conversion%20Library/${PORTVERSION} \
		http://dside.dyndns.org/files/rusxmms/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Library used by rusxmms for language autodetection

LIB_DEPENDS=	rcd.1:${PORTSDIR}/devel/librcd \
		enca.5:${PORTSDIR}/converters/enca \
		aspell.16:${PORTSDIR}/textproc/aspell

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack lthack libxml2
USE_GMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoheader:268

CPPFLAGS=	-I${LOCALBASE}/include
LIBS=		-L${LOCALBASE}/lib

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LIBS="${LIBS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

OPTIONS=	BDB "Translation database support" off \
		TRANSLATE "Online translation support" off \
		TOOLS "Install recode configuration utility" on \
		GTK1 "Use Gtk1 library/frontend" on \
		GTK2 "Use Gtk2 library/frontend" on

.include <bsd.port.options.mk>

.if defined(WITH_BDB)
USE_BDB=	41+
CPPFLAGS+=	-I${BDB_INCLUDE_DIR}
LIBS+=		-L${BDB_LIB_DIR}
CONFIGURE_ARGS+=--enable-bdb
.else
CONFIGURE_ARGS+=--disable-bdb
.endif

.if defined(WITH_TRANSLATE)
LIB_DEPENDS+=	translate.0:${PORTSDIR}/textproc/libtranslate
CONFIGURE_ARGS+=--enable-libtranslate
.else
CONFIGURE_ARGS+=--disable-libtranslate
.endif

.if defined(WITH_GTK1)
USE_GNOME+=	glib12 gtk12
PLIST_SUB+=	WITH_GTK1=""
.else
CONFIGURE_ENV+=	ac_cv_path_GTK_CONFIG=no GTK_CONFIG=no
PLIST_SUB+=	WITH_GTK1="@comment "
.endif

.if defined(WITH_GTK2)
USE_GNOME+=	gtk20
PLIST_SUB+=	WITH_GTK2=""
.else
CONFIGURE_ARGS+=--disable-glib2 --disable-gtk2
PLIST_SUB+=	WITH_GTK2="@comment "
.endif

.if defined(WITH_TOOLS)
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-rcc-config
PLIST_SUB+=	TOOLS=""
.else
PLIST_SUB+=	TOOLS="@comment "
.endif

pre-everything::
.if ${ARCH} == "i386"
.if defined(WITH_BDB) || defined (WITH_TRANSLATE)
	@${ECHO} 'BDB/LibTranslate support may cause breakages in depended apps on ${ARCH}'
	@${ECHO} 'Use it with caution'
.endif
.endif

.include <bsd.port.mk>
