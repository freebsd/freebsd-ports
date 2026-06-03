PORTNAME=	hidetopbar
DISTVERSION=	121
CATEGORIES=	deskutils gnome
PKGNAMEPREFIX=	gnome-shell-extension-
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Hide the topbar except in overview mode
WWW=		https://gitlab.gnome.org/tuxor1337/hidetopbar

LICENSE=	GPLv3

RUN_DEPENDS=	gnome-shell>=47.0:x11/gnome-shell \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		gnome tar:bz2
USE_GNOME=	glib20

NO_BUILD=	yes
NO_ARCH=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	tuxor1337
GL_TAGNAME=	bd46cf82

UUID_EXTENSION=	hidetopbar@mathieu.bidon.ca

SUB_FILES=	pkg-message
SUB_LIST=	UUID=${UUID_EXTENSION}

GLIB_SCHEMAS=	org.gnome.shell.extensions.hidetopbar.gschema.xml

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale
	${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/${UUID_EXTENSION}

do-install:
.for f in Settings.ui metadata.json
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/${UUID_EXTENSION}
.endfor
	${INSTALL_DATA} ${WRKSRC}/*.js \
		${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/${UUID_EXTENSION}
	${INSTALL_DATA} ${WRKSRC}/schemas/*.gschema.xml \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
	cd ${WRKSRC}/locale/ && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/locale/ "! -name *\.pot"

.include <bsd.port.mk>
