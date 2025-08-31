PORTNAME=	gnome-shell-extension-filesmenu
PORTVERSION=	0.0.0.20171125
PORTREVISION=	3
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Quickly navigate your file system
WWW=		https://github.com/bertoldia/files-menu

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Does not support recent gnome-shell

BUILD_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas

USES=		gettext gmake gnome localbase pkgconfig
USE_GNOME=	glib20

USE_GITHUB=	yes
GH_ACCOUNT=	bertoldia
GH_PROJECT=	files-menu
GH_TAGNAME=	10c13c8

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

post-patch:
		@${REINPLACE_CMD} -e 's|"3.26",|"3.28","3.26",|g' \
			${WRKSRC}/metadata.json
		@${RM} ${WRKSRC}/metadata.json.bak

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/gnome-shell-files-menu
		@cd ${WRKSRC} && ${COPYTREE_SHARE} . \
			${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/gnome-shell-files-menu

.include <bsd.port.mk>
