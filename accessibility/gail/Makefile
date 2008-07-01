# New ports collection makefile for:   gail
# Date Created:			12 February 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/gail/Makefile,v 1.72 2008/03/10 13:58:50 ahze Exp $
#

PORTNAME=	gail
PORTVERSION=	1.22.3
PORTREVISION?=	0
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An implementation of the ATK interfaces for GTK+ widgets

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

USE_GETTEXT=	yes
USE_XORG=	x11 xext
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack ltverhack gtk20 lthack referencehack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s|tests||" ${WRKSRC}/configure \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
