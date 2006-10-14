# New ports collection makefile for:	gedit2
# Date created:				14 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/editors/gedit/Makefile,v 1.48 2006/10/01 16:28:46 ahze Exp $
#

PORTNAME=	gedit
PORTVERSION=	2.16.1
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small but powerful text editor for GNOME 2 Desktop Environment

LIB_DEPENDS=	pspell.16:${PORTSDIR}/textproc/aspell

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack \
		libgnomeprintui libgnomeui eel2 gtksourceview desktopfileutils
WANT_GNOME=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB=	VERSION="2.16"

MAN1=		gedit.1
GCONF_SCHEMAS=	gedit.schemas gedit-file-browser.schemas

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

post-patch:
	@${REINPLACE_CMD} -e 's|make|${GMAKE}|g' \
	    	${WRKSRC}/bindings/python/Makefile.in

pre-build:
	${MKDIR} ${WRKSRC}/bindings/python/.deps
.for ff in gedit_la-gedit.Plo gedit_la-geditcommands.Plo gedit_la-geditutils.Plo
	${TOUCH} ${WRKSRC}/bindings/python/.deps/${ff}
.endfor

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
