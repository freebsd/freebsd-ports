# New ports collection makefile for:	gdesklets-goodweather-psi
# Date created:				17 November 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	goodweather
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	astro gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
PKGNAMESUFFIX=	-psi
DISTNAME=	GoodWeather-psi

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A desklet that displays current weather condition and forecast

RUN_DEPENDS=	${X11BASE}/share/gnome/gdesklets/Sensors/GoodWeather/__init__.py:${PORTSDIR}/astro/gdesklets-goodweather \
		${X11BASE}/share/gnome/gdesklets/Themes/Psi-Disp-Themes/backgrounds/dark/bg.png:${PORTSDIR}/deskutils/gdesklets-psi_themes

NO_BUILD=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
PLIST_FILES=	%%DATADIR%%/gdesklets/Displays/${NAME}/gfx/bg-bar.png \
		%%DATADIR%%/gdesklets/Displays/${NAME}/GoodWeather-psi.display
PLIST_DIRS=	%%DATADIR%%/gdesklets/Displays/${NAME}/gfx \
		%%DATADIR%%/gdesklets/Displays/${NAME}

NAME=		GoodWeather-psi
WRKSRC=		${WRKDIR}/${NAME}
DATADIR=	${PREFIX}/share/gnome
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx
	@${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/gdesklets/Displays/${NAME}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}.display ${DATADIR}/gdesklets/Displays/${NAME}/
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; s|%%NAME%%|${NAME}|g' \
		${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
