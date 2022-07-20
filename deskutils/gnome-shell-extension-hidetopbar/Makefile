PORTNAME=	gnome-shell-extension-hidetopbar
PORTVERSION=	0.0.0.20180511
PORTREVISION=	1
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Hide the topbar except in overview mode

LICENSE=	GPLv2

BUILD_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas

USES=		gettext gmake gnome pkgconfig
USE_GNOME=	glib20
USE_GITHUB=	yes
GLIB_SCHEMAS=	org.gnome.shell.extensions.hidetopbar.gschema.xml

GH_ACCOUNT=	mlutfy
GH_PROJECT=	hidetopbar
GH_TAGNAME=	7977769

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/hidetopbar@mathieu.bidon.ca
	${INSTALL_DATA} ${WRKSRC}/org.gnome.shell.extensions.hidetopbar.gschema.xml \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
	@${RM} -r ${WRKSRC}/org.gnome.shell.extensions.hidetopbar.gschema.xml
	cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/hidetopbar@mathieu.bidon.ca/

.include <bsd.port.mk>
