# New ports collection makefile for:	gconf2
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gconf2
PORTVERSION=	2.4.0.1
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/GConf/2.4
DISTNAME=	GConf-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A configuration database system for GNOME

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomehier orbit2 gtk20 libxml2 linc
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	@${MKDIR} ${PREFIX}/etc/gconf/gconf.xml.defaults/apps
	@${MKDIR} ${PREFIX}/etc/gconf/gconf.xml.defaults/schemas/apps
	@${MKDIR} ${PREFIX}/etc/gconf/schemas

.include <bsd.port.mk>
