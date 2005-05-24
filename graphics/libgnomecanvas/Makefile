# New ports collection makefile for:	gnomecanvas
# Date created:				18 May 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgnomecanvas
PORTVERSION=	2.10.2
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.10
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A graphics library for GNOME

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomehack libglade2 libartlgpl2
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
