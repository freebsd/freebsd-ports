PORTNAME=	gnome-shell-extension-audio-output-switcher
PORTVERSION=	0.0.0.20171022
PORTREVISION=	3
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome-shell audio output switcher
WWW=		https://github.com/anduchs/audio-output-switcher

BROKEN=		Does not support recent gnome-shell

BUILD_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gnome-shell>=0:x11/gnome-shell \
		gsettings-desktop-schemas>=3.12.0:devel/gsettings-desktop-schemas

USES=		gettext gmake gnome localbase pkgconfig
USE_GNOME=	glib20
USE_GITHUB=	yes

GH_ACCOUNT=	adaxi
GH_PROJECT=	audio-output-switcher
GH_TAGNAME=	89e6e29

PKGMESSAGE=	../gnome-shell-extra-extensions/pkg-message.slaves

NO_BUILD=	yes

post-patch:
		@${REINPLACE_CMD} -e 's|"3.26"|"3.26", "3.28"|g' \
			${WRKSRC}/metadata.json

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/audio-output-switcher@anduchs
		@(cd ${WRKSRC} && ${CP} -pPR * \
			${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/audio-output-switcher@anduchs)

.include <bsd.port.mk>
