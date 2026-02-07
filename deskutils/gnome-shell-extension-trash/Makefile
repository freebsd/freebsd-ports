PORTNAME=	gnome-shell-extension-trash
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome-shell trash indicator
WWW=		https://github.com/bertoldia/gnome-shell-trash-extension

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Does not support recent gnome-shell

BUILD_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas

USES=		gettext gmake gnome pkgconfig
USE_GNOME=	glib20
USE_GITHUB=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GH_ACCOUNT=	bertoldia
GH_PROJECT=	gnome-shell-trash-extension
GH_TAGNAME=	ad5cc74

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|"3.26",|"3.28","3.26",|g' \
		${WRKSRC}/metadata.json

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/gnome-shell-trash-extension
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/gnome-shell-trash-extension

.include <bsd.port.mk>
