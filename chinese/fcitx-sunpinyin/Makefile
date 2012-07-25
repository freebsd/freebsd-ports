# New ports collection makefile for:	fcitx-sunpinyin
# Date created:				10 Nov 2011
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fcitx-sunpinyin
PORTVERSION=	0.3.8
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	SunPinyin support for Fcitx

LIB_DEPENDS=	fcitx-config:${PORTSDIR}/chinese/fcitx
BUILD_DEPENDS=	zh-sunpinyin>=2.0.4.r2:${PORTSDIR}/chinese/sunpinyin
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_XZ=		yes
USE_GETTEXT=	yes
USE_CMAKE=	yes
USE_GNOME=	intltool
INSTALLS_ICONS=	yes

PROJECTHOST=	fcitx

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
