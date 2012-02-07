# New ports collection makefile for:	fcitx-googlepinyin
# Date created:				11 Nov 2011
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fcitx-googlepinyin
PORTVERSION=	0.1.4
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	A libgooglepinyin support for Fcitx

LIB_DEPENDS=	fcitx-config.4:${PORTSDIR}/chinese/fcitx \
		googlepinyin.0:${PORTSDIR}/chinese/libgooglepinyin

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_CMAKE=	yes
USE_GNOME=	intltool

PROJECTHOST=	fcitx

.include <bsd.port.mk>
