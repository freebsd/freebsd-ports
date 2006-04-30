# New ports collection makefile for:	gedit2
# Date created:				14 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/editors/gedit/Makefile,v 1.33 2006/04/13 07:52:34 bland Exp $
#

PORTNAME=	gedit
PORTVERSION=	2.14.2
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small but powerful text editor for Gnome 2 Desktop Environment

LIB_DEPENDS=	pspell.16:${PORTSDIR}/textproc/aspell

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack \
		libgnomeprintui libgnomeui eel2 gtksourceview desktopfileutils
WANT_GNOME=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB=	VERSION="2.14"

MAN1=		gedit.1
GCONF_SCHEMAS=	gedit.schemas

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mpygnomedesktop}!=""
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_GNOME+=	pygnomedesktop
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
