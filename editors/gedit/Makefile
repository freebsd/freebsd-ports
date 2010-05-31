# New ports collection makefile for:	gedit2
# Date created:				14 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/editors/gedit/Makefile,v 1.120 2010/04/19 15:33:49 kwm Exp $
#

PORTNAME=	gedit
PORTVERSION=	2.30.2
PORTREVISION=	1
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small but powerful text editor for GNOME 2 Desktop Environment

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant \
		soup-2.4.1:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_XORG=	sm
USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2 gtksourceview2 \
		desktopfileutils gnomedocutils ltasneededhack
WANT_GNOME=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB=	VERSION="2.20"

MAN1=		gedit.1
GCONF_SCHEMAS=	gedit.schemas gedit-file-browser.schemas

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mpygtksourceview}!=""
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_GNOME+=	pygtksourceview
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

#pre-build:
#	${MKDIR} ${WRKSRC}/bindings/python/.deps
#.for ff in gedit_la-gedit.Plo gedit_la-geditcommands.Plo gedit_la-geditutils.Plo
#	${TOUCH} ${WRKSRC}/bindings/python/.deps/${ff}
#.endfor

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
