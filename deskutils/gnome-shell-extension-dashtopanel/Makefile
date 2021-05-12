# Created by: Alexander Vereeken <Alexander88207@protonmail.com>

PORTNAME=	gnome-shell-extension-dashtopanel
PORTVERSION=	v42
CATEGORIES=	deskutils

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Icon taskbar for the Gnome Shell

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed \
		git:devel/git \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		gettext>=0:devel/gettext

BINARY_ALIAS=	sed=gsed

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	home-sweet-gnome
GH_PROJECT=	dash-to-panel

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/|${PREFIX}/share/|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
