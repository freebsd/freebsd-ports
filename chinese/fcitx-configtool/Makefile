# New ports collection makefile for:	fcitx-configtool
# Date created:				09 Nov 2011
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fcitx-configtool
PORTVERSION=	0.3.1
CATEGORIES=	chinese x11
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	lichray@gmail.com
COMMENT=	Fcitx IM configure tool

LIB_DEPENDS=	fcitx-config.4:${PORTSDIR}/chinese/fcitx

USE_BZIP2=	yes
USE_GNOME=	gtk20 intltool gnomehack
USE_GETTEXT=	yes
USE_CMAKE=	yes

PROJECTHOST=	fcitx

PLIST_FILES=	bin/fcitx-config-gtk \
		share/locale/zh_CN/LC_MESSAGES/fcitx-configtool.mo

.include <bsd.port.mk>
