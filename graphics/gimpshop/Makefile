# New ports collection makefile for:    The GIMP
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gimp
PORTVERSION=	1.3.11
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		ftp://ftp.ameth.org/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,} \
		ftp://ftp.bic.mni.mcgill.ca/pub/mpeg/:mpeg \
		http://starship.python.net/~gward/mpeglib/:mpeg
MASTER_SITE_SUBDIR=	gimp/v${PORTVERSION:R}/v${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		mpeg_lib-1.3.1.tar.gz:mpeg

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20 \
		gimpprint.2:${PORTSDIR}/print/gimp-print \
		art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2 \
		aa.1:${PORTSDIR}/graphics/aalib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

SHLIBVER?=	2

NO_LATEST_LINK=	yes

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
PLIST_SUB=	SHLIBVER="${SHLIBVER}"
CONFIGURE_ARGS=	--disable-perl \
		--with-html-dir=${PREFIX}/share/doc/gimp \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

GIMP_DISTFILE=	${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAN1=		gimp-1.3.1 gimptool-1.3.1 gimp-remote-1.3.1
MAN5=		gimprc-1.3.5

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/_gtkmodule.so:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/_gtkmodule.so:${PORTSDIR}/x11-toolkits/py-gtk2
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=	PYTHON:=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	PYTHON:="@comment "
.endif

.if exists(${X11BASE}/libdata/pkgconfig/libpanelapplet-2.0.pc)
RUN_DEPENDS+=	gnome-panel:${PORTSDIR}/x11/gnomepanel
CONFIGURE_ARGS+=	--with-gnome-datadir=${X11BASE}/share/gnome
PLIST_SUB+=	GNOME:=""
.else
PLIST_SUB+=	GNOME:="@comment "
.endif

#.if exists(${X11BASE}/libdata/pkgconfig/libgtkhtml-2.0.pc) || defined(WITH_HTML_HELP_BROWSER)
#LIB_DEPENDS+=	gtkhtml-2.0:${PORTSDIR}/www/libgtkhtml
#.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "gimp-devel has the following tunable option(s):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "		WITH_PYTHON=yes	Turns on Python-Fu support"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
