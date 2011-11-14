# New ports collection makefile for:	fcitx-cloudpinyin
# Date created:				11 Nov 2011
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fcitx-cloudpinyin
PORTVERSION=	0.1.2
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	A cloud-based Pinyin module for Fcitx

LIB_DEPENDS=	fcitx-config.4:${PORTSDIR}/chinese/fcitx \
		curl:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_CMAKE=	yes
USE_GNOME=	intltool

PROJECTHOST=	fcitx

.include <bsd.port.mk>
