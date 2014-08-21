# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-sunpinyin
PORTVERSION=	0.3.9
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SunPinyin support for Fcitx

LIB_DEPENDS=	libfcitx-config.so:${PORTSDIR}/chinese/fcitx
BUILD_DEPENDS=	zh-sunpinyin>=2.0.4.r2:${PORTSDIR}/chinese/sunpinyin
RUN_DEPENDS=	zh-sunpinyin>=2.0.4.r2:${PORTSDIR}/chinese/sunpinyin

USES=		cmake gettext pkgconfig tar:xz
USE_GNOME=	intltool
INSTALLS_ICONS=	yes

PROJECTHOST=	fcitx

.include <bsd.port.mk>
