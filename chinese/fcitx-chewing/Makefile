# New ports collection makefile for:	fcitx-chewing
# Date created:				6 Feb 2012
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fcitx-chewing
PORTVERSION=	0.1.0
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Chewing support for Fcitx

LIB_DEPENDS=	fcitx-config.4:${PORTSDIR}/chinese/fcitx \
		chewing.3:${PORTSDIR}/chinese/libchewing

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_CMAKE=	yes
USE_GNOME=	intltool

PROJECTHOST=	fcitx

.include <bsd.port.mk>
