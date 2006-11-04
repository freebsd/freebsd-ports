# New ports collection makefile for:    The GIMP
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#   $MCom: ports/graphics/gimp-devel/Makefile,v 1.24 2006/10/13 23:42:43 marcus Exp $
#

PORTNAME=	gimp
PORTVERSION=	2.3.9
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		http://gimp.mirrors.hoobly.com/%SUBDIR%/ \
		http://ftp.gwdg.de/pub/misc/grafik/gimp/%SUBDIR%/ \
		ftp://ftp.fh-heilbronn.de/mirrors/ftp.gimp.org/%SUBDIR%/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/ftp.gimp.org/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/%SUBDIR%,} \
		${MASTER_SITE_LOCAL:S|$|ahze/|:S|$|:gut|}
MASTER_SITE_SUBDIR=	gimp/v${PORTVERSION:R} \
		ahze:gut

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${EXTRA_DISTFILES}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNU Image Manipulation Program development version

LIB_DEPENDS=	wmf.2:${PORTSDIR}/graphics/libwmf \
		poppler-glib.1:${PORTSDIR}/graphics/poppler-gtk \
		aa.1:${PORTSDIR}/graphics/aalib \
		mng.1:${PORTSDIR}/graphics/libmng \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

CONFLICTS=	gimp-1.* gimp-2.2.*
NO_LATEST_LINK=	yes

SHLIBVER?=	0

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack intltool intlhack gtk20 libartlgpl2 ltverhack
WANT_GNOME=	yes
USE_GCC=	3.4+
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
PLIST_SUB=	SHLIBVER="${SHLIBVER}"
CONFIGURE_ARGS=	--disable-perl \
		--with-html-dir=${DOCSDIR} \
		--disable-gtk-doc \
		--enable-static \
		--with-gimpprint
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

GIMP_DISTFILE=	${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAN1=	gimp-2.3.1 gimp-remote-2.3.1 gimptool-2.0.1
MAN5=	gimprc-2.3.5

OPTIONS=	DEBUG "debugging" off \
		PYTHON "Python-Fu support" off \
		RSVG "SVG format support" on \
		PRINT "Gutenprint plugin" on \
		GNOMEPRINT "GNOME printing plugin" on \
		MP "multiple processor support" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	does not build on 4.X
.endif

#.if defined(WITHOUT_EXIF)
CONFIGURE_ARGS+=	--without-libexif
#.else
#LIB_DEPENDS+=		exif.12:${PORTSDIR}/graphics/libexif
#.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=		yes
# we need to manually include this, because USE_PYTHON is defined
# # after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_GNOME+=		pygtk2
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=		PYTHON:=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=		PYTHON:="@comment "
.endif

.if defined(WITHOUT_RSVG)
CONFIGURE_ARGS+=	--without-librsvg
PLIST_SUB+=		SVG="@comment "
.else
USE_GNOME+=		librsvg2
PLIST_SUB+=		SVG=""
.endif

.if !defined(WITHOUT_PRINT)
LIB_DEPENDS+=	gutenprintui2.1:${PORTSDIR}/print/gutenprint
EXTRA_DISTFILES+=	gimp2-gutenprint-2${EXTRACT_SUFX}:gut
GUT_WRKSRC=	${WRKDIR}/gimp2-gutenprint
PKGCONFIG?=		${LOCALBASE}/bin/pkg-config
GUTENPRINT_CFLAGS=	`${PKGCONFIG} --cflags gutenprintui2`
GUTENPRINT_LIBS=	`${PKGCONFIG} --libs gutenprintui2`
GUT_MAKE_ENV=	GUTENPRINT_CFLAGS="${GUTENPRINT_CFLAGS}" \
		GUTENPRINT_LIBS="${GUTENPRINT_LIBS}"
PLIST_SUB+=	GPRINT=""
.else
PLIST_SUB+=	GPRINT="@comment "
.endif

.if !defined(WITHOUT_GNOMEPRINT)
USE_GNOME+=		libgnomeprintui
PLIST_SUB+=		PRINT=""
.else
CONFIGURE_ARGS+=	--without-gnomeprint
PLIST_SUB+=		PRINT="@comment "
.endif

.if defined(WITH_MP)
CONFIGURE_ARGS+=	--enable-mp
.endif

.if ${HAVE_GNOME:Mgnomepanel}!=""
USE_GNOME+=		gnomepanel desktopfileutils gnomehier
CONFIGURE_ARGS+=	--with-desktop-dir=${LOCALBASE}/share/gnome
CONFIGURE_ENV+=		GIMP_THREAD_LIBS=${PTHREAD_LIBS}
PKGNAMESUFFIX:=		-gnome
PLIST_SUB+=		GTK="gnome/" GNOMEPANEL:=""
GNOME_ENABLED=		yes
.else
PLIST_SUB+=		GTK="" GNOMEPANEL:="@comment "
CONFIGURE_ENV+=		GIMP_THREAD_LIBS=${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--without-desktop-dir
.endif

post-extract:
.if !defined(WITHOUT_PRINT)
	${RM} -rf ${WRKSRC}/plug-ins/print
	${MKDIR} ${WRKSRC}/plug-ins/print
	${CP} -f ${GUT_WRKSRC}/* ${WRKSRC}/plug-ins/print
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|"libpng"|"libpng12"|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@mandir@|${PREFIX}/man|' \
		${WRKSRC}/docs/Makefile.in

post-build:
.if !defined(WITHOUT_PRINT)
	@(cd ${WRKSRC}/plug-ins/print; ${SETENV} ${GUT_MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endif

post-install:
.if !defined(WITHOUT_PRINT)
	@(cd ${WRKSRC}/plug-ins/print; ${SETENV} ${GUT_MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif
.if defined(GNOME_ENABLED)
	@-update-desktop-database
.endif

.include <bsd.port.post.mk>
