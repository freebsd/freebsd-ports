# New ports collection makefile for:    The GIMP
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gimp
PORTVERSION=	1.1.18
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/unstable/old/v${PORTVERSION}/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/gimp/unstable/old/v${PORTVERSION}/ \
		ftp://ftp.ameth.org/pub/mirrors/ftp.gimp.org/gimp/unstable/old/v${PORTVERSION}/

MAINTAINER=	vanilla@FreeBSD.org

.if !defined (WITHOUT_PERL)
BUILD_DEPENDS=	perldl:${PORTSDIR}/math/PDL \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk
RUN_DEPENDS=	perldl:${PORTSDIR}/math/PDL \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk
.endif
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		aa.1:${PORTSDIR}/graphics/aalib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		mpeg.1:${PORTSDIR}/graphics/mpeg-lib \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		intl.1:${PORTSDIR}/devel/gettext

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
.if defined (WITHOUT_PERL)
CONFIGURE_ARGS=	--disable-perl
.endif
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gimp.1 gimptool.1
MAN5=		gimprc.5

.if !defined(WITH_GNOME) && exists(${X11BASE}/bin/gnome-config)
WITH_GNOME=	yes
.endif

.if defined(WITHOUT_PERL)
PLISTORIG=		${PKGDIR}/PLIST
PLIST=			${WRKDIR}/PLIST
.else
PLISTORIG=		${PKGDIR}/PLIST.perl
PLIST=			${WRKDIR}/PLIST.perl
pre-fetch:
	@${ECHO} -n "If you want to compile without perl support "
	@${ECHO} "'make -DWITHOUT_PERL' instead"
.endif

.if defined(WITH_GNOME) && ${WITH_GNOME} == yes
LIB_DEPENDS+=	gtkxmhtml.3:${PORTSDIR}/x11/gnomelibs
pre-install:
	@${CAT} ${PLISTORIG} > ${PLIST}
.else
pre-install:
	@${SED} -e '/helpbrowser/d' ${PLISTORIG} > ${PLIST}
.endif

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/gimp.setfont ${PREFIX}/bin
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
