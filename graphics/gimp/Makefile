# New ports collection makefile for:    The GIMP
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gimp
PORTVERSION=	2.0.pre2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.fh-heilbronn.de/mirrors/ftp.gimp.org/%SUBDIR%/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,}
#MASTER_SITE_SUBDIR=	gimp/v${PORTVERSION:R}/v${PORTVERSION}
MASTER_SITE_SUBDIR=	gimp/v${PORTVERSION:R}/testing
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.pre/pre/}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNU Image Manipulation Program (unstable development version)

BUILD_DEPENDS=	intltool-extract:${PORTSDIR}/textproc/intltool
LIB_DEPENDS=	aa.1:${PORTSDIR}/graphics/aalib \
		exif.10:${PORTSDIR}/graphics/libexif \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		mng.1:${PORTSDIR}/graphics/libmng \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		wmf.2:${PORTSDIR}/graphics/libwmf

SHLIBVER?=	2

NO_LATEST_LINK=	yes

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gtk20 libartlgpl2 librsvg2
WANT_GNOME=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
PLIST_SUB=	SHLIBVER="${SHLIBVER}"
CONFIGURE_ARGS=	--disable-perl \
		--with-html-dir=${PREFIX}/share/doc/gimp \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

GIMP_DISTFILE=	${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAN1=		gimp-1.3.1 gimptool-2.0.1 gimp-remote-1.3.1
MAN5=		gimprc-1.3.5

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/_gtk.so:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/_gtk.so:${PORTSDIR}/x11-toolkits/py-gtk2
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=		PYTHON:=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=		PYTHON:="@comment "
.endif

.if defined(WITHOUT_PRINT)
CONFIGURE_ARGS+=	--disable-print
PLIST_SUB+=		PRINT="@comment "
.else
LIB_DEPENDS+=		gimpprint.2:${PORTSDIR}/print/gimp-print
PLIST_SUB+=		PRINT=""
.endif

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/libdata/pkgconfig/libgtkhtml-2.0.pc)
WITH_HTML_HELP_BROWSER=	yes
.endif

.if ${HAVE_GNOME:Mgnomepanel}!=""
USE_GNOME+=		gnomepanel
CONFIGURE_ARGS+=	--with-desktop-dir=${X11BASE}/share/gnome
PKGNAMESUFFIX=		-gnome
.endif

.if defined(WITH_HTML_HELP_BROWSER)
USE_GNOME+=		libgtkhtml
PLIST_SUB+=		HELPBROWSER:=""
.else
PLIST_SUB+=		HELPBROWSER:="@comment "
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "gimp-devel has the following tunable option(s):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_PYTHON=yes		Turns on Python-Fu support"
	@${ECHO_MSG} "	WITHOUT_PRINT=yes	Turns off GIMP printing"
	@${ECHO_MSG} "	WITH_HTML_HELP_BROWSER=yes	Turns on the GIMP help browser"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
