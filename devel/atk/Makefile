# New ports collection makefile for:   atk
# Date Created:			14 May 2001
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	atk
PORTVERSION=	1.2.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME} \
		ftp://ftp.gtk.org/pub/gtk/v2.0/
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.2
#MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
#		ftp://ftp.cs.umn.edu/pub/gimp/%SUBDIR%/ \
#		http://www.ameth.org/gimp/%SUBDIR%/ \
#		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,}
#MASTER_SITE_SUBDIR=	gtk/v1.3
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	glib-2.0.200:${PORTSDIR}/devel/glib20

USE_BZIP2=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack
CONFIGURE_ARGS=	--enable-static \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.mk>
