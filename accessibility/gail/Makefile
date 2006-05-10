# New ports collection makefile for:   gail
# Date Created:			12 February 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/gail/Makefile,v 1.44 2006/04/23 22:21:28 mezz Exp $
#

PORTNAME=	gail
PORTVERSION=	1.8.11
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An implementation of the ATK interfaces for GTK+ widgets

USE_BZIP2=	yes
PREFIX?=	${X11BASE}

.if !defined(REFERENCE_PORT)

PORTREVISION=	1

USE_GETTEXT=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack libgnomecanvas lthack referencehack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s|tests||" ${WRKSRC}/configure \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
