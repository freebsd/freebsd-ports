# New ports collection makefile for:    The GIMP
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gimp
PORTVERSION=	1.1.27
CATEGORIES=	graphics gnome
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/unstable/v${PORTVERSION}/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/gimp/unstable/v${PORTVERSION}/ \
		ftp://ftp.ameth.org/pub/mirrors/ftp.gimp.org/gimp/unstable/v${PORTVERSION}/ \
		ftp://ftp.gimp.org/pub/gimp/unstable/old/v${PORTVERSION}/

MAINTAINER=	vanilla@FreeBSD.org

LIB_DEPENDS=	aa.1:${PORTSDIR}/graphics/aalib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		mpeg.1:${PORTSDIR}/graphics/mpeg-lib \
		png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

SHLIBVER?=	${PORTVERSION:S/1.//g}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_GTK=	yes
#WANT_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
PLIST_SUB=	SHLIBVER="${SHLIBVER}"

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gimp.1 gimptool.1 gimp-remote.1
MAN5=		gimprc.5

.if defined(WITH_PERL)
PERL_DEPENDS=	perldl:${PORTSDIR}/math/PDL \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent
BUILD_DEPENDS+=	${PERL_DEPENDS}
RUN_DEPENDS+=	${PERL_DEPENDS}
PLIST_SUB+=	PERL:=""
.else
CONFIGURE_ARGS=	--disable-perl
PLIST_SUB+=	PERL:="@comment "
pre-fetch:
	@${ECHO} -n "If you want to compile with perl support use "
	@${ECHO} "'make -DWITH_PERL' instead"
.endif

.include <bsd.port.pre.mk>

#.if defined(HAVE_GNOME)
#USE_GNOME=	yes
#.endif

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/gimp.setfont ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
