# New ports collection makefile for:   glib13
# Date Created:			28 July 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glib
PORTVERSION=	2.0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:S,%SUBDIR%,sources/${PORTNAME}/2.0,} \
		ftp://ftp.gtk.org/pub/gtk/v2.0/ \
		ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.cs.umn.edu/pub/gimp/%SUBDIR%/ \
		http://www.ameth.org/gimp/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gtk/v${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

NO_LATEST_LINK=	yes

USE_BZIP2=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack
USE_GMAKE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS=	--enable-static --with-libiconv=gnu
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=		glib-genmarshal.1 glib-mkenums.1

.include <bsd.port.mk>
