# New ports collection makefile for:   atk
# Date Created:			14 May 2001
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	atk
PORTVERSION=	1.2.4
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
COMMENT=	A GNOME accessibility toolkit (ATK)

USE_BZIP2=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
USE_GNOME=	gnomehack glib20
CONFIGURE_ARGS=	--enable-static \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
