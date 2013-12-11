# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-sunpinyin
PORTVERSION=	0.3.9
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	SunPinyin support for Fcitx

LIB_DEPENDS=	libfcitx-config.so:${PORTSDIR}/chinese/fcitx
BUILD_DEPENDS=	zh-sunpinyin>=2.0.4.r2:${PORTSDIR}/chinese/sunpinyin
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_XZ=		yes
USES=		cmake gettext pkgconfig
USE_GNOME=	intltool
INSTALLS_ICONS=	yes

PROJECTHOST=	fcitx

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
