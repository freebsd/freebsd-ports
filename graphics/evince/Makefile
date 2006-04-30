# New ports collection makefile for:	evince
# Date created:				09 January 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/evince/Makefile,v 1.50 2006/04/24 00:54:32 ahze Exp $
#

PORTNAME=	evince
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	graphics print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.5

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 multi-format document viewer

LIB_DEPENDS=	poppler-glib.1:${PORTSDIR}/graphics/poppler-gtk

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GHOSTSCRIPT=yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui libgnomeprintui \
		desktopfileutils gnomedocutils
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

GCONF_SCHEMAS=	evince.schemas evince-thumbnailer.schemas

OPTIONS=	DVI		"Enable DVI viewer support"		off \
		T1LIB		"Enable T1LIB for TYPE1 fonts to DVI (Enables DVI)"	off \
		NAUTILUS	"Enable Nautilus plugin"		on  \
		DBUS		"Enable D-BUS support"			on \
		COMICS		"Enable comic book archives support"	off
#		DJVU		"Enable DJVU support"			off

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) || defined(PARALLEL_PACKAGE_BUILD) \
		|| exists(${LOCALBASE}/lib/libdbus-glib-1.so)
WITH_DBUS=	yes
.endif

.if defined(WITH_DVI) || defined(WITH_T1LIB)
BUILD_DEPENDS+=	tex:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS+=	tex:${PORTSDIR}/print/teTeX-base

CONFIGURE_ARGS+=	--enable-dvi
GCONF_SCHEMAS+=	evince-thumbnailer-dvi.schemas
. if defined(WITH_T1LIB)
LIB_DEPENDS+=	t1.5:${PORTSDIR}/devel/t1lib

CONFIGURE_ARGS+=	--enable-t1lib
. endif
.endif

.if !defined(WITHOUT_NAUTILUS)
USE_GNOME+=		nautilus2
CONFIGURE_ARGS+=	--enable-nautilus
PLIST_SUB+=		NAUTILUS=""
.else
CONFIGURE_ARGS+=	--disable-nautilus
PLIST_SUB+=		NAUTILUS="@comment "
.endif

.if exists(${X11BASE}/bin/djview)
DJVU_DIR?=	# empty
.else
DJVU_DIR?=	-nox11
.endif

# DJVU is broken, need older version of djvu
#.if defined(WITH_DJVU)
#LIB_DEPENDS+=		djvulibre.17:${PORTSDIR}/graphics/djvulibre${DJVU_DIR}
#CONFIGURE_ARGS+=	--enable-djvu
#GCONF_SCHEMAS+=		evince-thumbnailer-djvu.schemas
#.else
CONFIGURE_ARGS+=	--disable-djvu
#.endif

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus
.endif

.if defined(WITH_COMICS)
CONFIGURE_ARGS+=	--enable-comics
GCONF_SCHEMAS+=	evince-thumbnailer-comics.schemas

RUN_DEPENDS=	unrar:${PORTSDIR}/archivers/unrar \
		unzip:${PORTSDIR}/archivers/unzip
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lt1lib|-lt1 -lm| ; \
		s|execinfo.h|#|g' \
		${WRKSRC}/configure \
		${WRKSRC}/dvi/mdvi-lib/Makefile.in

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
