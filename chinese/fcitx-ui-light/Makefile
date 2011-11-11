# New ports collection makefile for:	fcitx-ui-light
# Date created:				09 Nov 2011
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fcitx-ui-light
PORTVERSION=	0.1.2
CATEGORIES=	chinese x11
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	lichray@gmail.com
COMMENT=	An alternative light weight UI for Fcitx

LIB_DEPENDS=	fcitx-config.4:${PORTSDIR}/chinese/fcitx \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XORG=	x11 xft xpm
USE_CMAKE=	yes
USE_GNOME=	intltool

PROJECTHOST=	fcitx

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
