# New ports collection makefile for:    The GIMP
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gimp
PORTVERSION=	1.1.24
CATEGORIES=	graphics gnome
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/unstable/v${PORTVERSION}/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/gimp/unstable/v${PORTVERSION}/ \
		ftp://ftp.ameth.org/pub/mirrors/ftp.gimp.org/gimp/unstable/v${PORTVERSION}/ \
		ftp://ftp.gimp.org/pub/gimp/unstable/old/v${PORTVERSION}/

MAINTAINER=	vanilla@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		aa.1:${PORTSDIR}/graphics/aalib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		mpeg.1:${PORTSDIR}/graphics/mpeg-lib \
		png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
SHLIBVER?=	${PORTVERSION:S/1.//g}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
PLIST_SUB=	SHLIBVER="${SHLIBVER}"

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gimp.1 gimptool.1
MAN5=		gimprc.5

.if !defined(WITH_PERL)
CONFIGURE_ARGS=	--disable-perl
PLIST_SUB+=	PERL:="@comment "
.else
BUILD_DEPENDS+=	perldl:${PORTSDIR}/math/PDL \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk
RUN_DEPENDS+=	perldl:${PORTSDIR}/math/PDL \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk
PLIST_SUB+=	PERL:=""
.endif

.if defined(WITH_GNOME) || (exists(${X11BASE}/bin/gnome-config) \
    && !defined(WITHOUT_GNOME))
LIB_DEPENDS+=	gtkxmhtml.4:${PORTSDIR}/x11/gnomelibs
PLIST_SUB+=	GNOME:=""
.else
PLIST_SUB+=	GNOME:="@comment "
.endif

.if !defined(WITH_PERL)
pre-fetch:
	@${ECHO} -n "If you want to compile with perl support use "
	@${ECHO} "'make -DWITH_PERL' instead"
.endif

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/gimp.setfont ${PREFIX}/bin
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
