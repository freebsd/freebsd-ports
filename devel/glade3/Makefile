# New ports collection makefile for:	glade3
# Date created:		Sun May 22 17:22:53 CEST 2005
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/glade3/Makefile,v 1.29 2007/03/13 17:16:00 mezz Exp $
#

PORTNAME=	glade3
PORTVERSION=	3.2.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A user interface builder for GTK+/GNOME

INSTALLS_ICONS=	yes
USE_XLIB=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 libxml2 gnomeprefix gnomehack \
		gnomedocutils desktopfileutils
WANT_GNOME=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

DOCSDIR=	${PREFIX}/share/doc/gladeui

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=	libgnomeui
CONFIGURE_ARGS+=--enable-gnome
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-gnome
.else
CONFIGURE_ARGS+=--disable-gnome
.endif

.if ${HAVE_GNOME:Mpygtk2}!=""
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_GNOME+=	pygtk2
PLIST_SUB+=	PYTHON:=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON:="@comment "
.endif

post-install:
	${MKDIR} ${PREFIX}/lib/glade3/bindings
	@-update-desktop-database

.include <bsd.port.post.mk>
