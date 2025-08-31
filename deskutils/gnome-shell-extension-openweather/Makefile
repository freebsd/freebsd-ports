PORTNAME=	gnome-shell-extension-openweather
DISTVERSION=	139
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	https://github.com/penguin-teal/gnome-openweather/releases/download/${DISTVERSIONFULL}/
DISTNAME=	${PORTNAME}refined-${DISTVERSIONFULL}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenWeather extension for the GNOME Shell
WWW=		https://github.com/penguin-teal/gnome-openweather

LICENSE=	GPLv3

RUN_DEPENDS=	gnome-shell>=47.0:x11/gnome-shell \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		gnome
USE_GNOME=	glib20

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

UUID_EXTENSION=	openweather-extension@penguin-teal.github.io

SUB_FILES=	pkg-message
SUB_LIST=	UUID=${UUID_EXTENSION}

GLIB_SCHEMAS=	org.gnome.shell.extensions.openweatherrefined.gschema.xml

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/glib-2.0/schemas
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale
	${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/${UUID_EXTENSION}

do-install:
	${INSTALL_DATA} ${WRKSRC}/schemas/*.gschema.xml \
		${STAGEDIR}${PREFIX}/share/glib-2.0/schemas/
	${RM} -Rf ${WRKSRC}/schemas/
	cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/gnome-shell/extensions/${UUID_EXTENSION}

.include <bsd.port.mk>
