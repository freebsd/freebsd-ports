# New ports collection makefile for:	fcitx-anthy
# Date created:				18 Jul 2012
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fcitx-anthy
PORTVERSION=	0.1.0
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Anthy support for Fcitx

LIB_DEPENDS=	fcitx-config:${PORTSDIR}/chinese/fcitx \
		anthy:${PORTSDIR}/japanese/anthy

USE_XZ=		yes
USE_GETTEXT=	yes
USE_CMAKE=	yes
USE_GNOME=	intltool

PROJECTHOST=	fcitx

.include <bsd.port.mk>
