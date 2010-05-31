# New ports collection makefile for:   gnome-globalmenu
# Date created:        27 February 2009
# Whom:                Gustavo Perez
#
# $FreeBSD$
#

PORTNAME=		gnome-globalmenu
PORTVERSION=		0.7.5
PORTREVISION=	5
CATEGORIES=		deskutils
MASTER_SITES=		http://gnome2-globalmenu.googlecode.com/files/

MAINTAINER=		gustau.perez@gmail.com
COMMENT=		Global menu for gnome

LIB_DEPENDS=		notify.1:${PORTSDIR}/devel/libnotify

USE_GNOME=		gnomepanel gnomedesktop

USE_BZIP2=		yes
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:22 automake:19:env autoheader:262:env
INSTALLS_ICONS=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

MAN1=			gnome-globalmenu.1

GCONF_SCHEMAS=		gnome-globalmenu.schemas

post-install:
		@${INSTALL_DATA} ${WRKSRC}/applet/GlobalMenu_PanelApplet.server \
			${LOCALBASE}/libdata/bonobo/servers
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Leaves files behind on deinstall on sparc64
.endif

.include <bsd.port.post.mk>
