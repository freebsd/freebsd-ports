PORTNAME=	simple-weather
DISTVERSIONPREFIX=	v
DISTVERSION=	48.2.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	https://github.com/romanlefler/SimpleWeather/releases/download/${DISTVERSIONFULL}/
PKGNAMEPREFIX=	gnome-shell-extension-

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Highly configurable weather indicator for GNOME Shell
WWW=		https://github.com/romanlefler/SimpleWeather

LICENSE=	GPLv3+

RUN_DEPENDS=	gnome-shell>=48.0:x11/gnome-shell \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		gnome zip
USE_GNOME=	glib20

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

UUID_EXTENSION=	simple-weather@romanlefler.com

SUB_FILES=	pkg-message
SUB_LIST=	UUID=${UUID_EXTENSION}

GLIB_SCHEMAS=	org.gnome.shell.extensions.simple-weather.gschema.xml

# Support GNOME Shell 47.x too
post-patch:
	${REINPLACE_CMD} -i "" -e 's|46|47|' ${WRKSRC}/metadata.json

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale
	${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/${UUID_EXTENSION}

do-install:
	${INSTALL_DATA} ${WRKSRC}/schemas/*.gschema.xml \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
	${RM} -Rf ${WRKSRC}/schemas/
	cd ${WRKSRC}/locale && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/locale
	${RM} -Rf ${WRKSRC}/locale
	cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/${UUID_EXTENSION}

.include <bsd.port.mk>
