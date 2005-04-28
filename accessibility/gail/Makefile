# New ports collection makefile for:   gail
# Date Created:			12 February 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gail
PORTVERSION=	1.8.4
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.8
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An implementation of the ATK interfaces for GTK+ widgets

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
USE_GNOME=	gnomehack libgnomecanvas lthack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s|tests||" ${WRKSRC}/configure \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
