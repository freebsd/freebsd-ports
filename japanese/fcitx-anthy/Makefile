# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-anthy
PORTVERSION=	0.1.1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Anthy support for Fcitx

LIB_DEPENDS=	fcitx-config:${PORTSDIR}/chinese/fcitx \
		anthy:${PORTSDIR}/japanese/anthy

USE_XZ=		yes
USES=		cmake gettext pkgconfig
USE_GNOME=	intltool

PROJECTHOST=	fcitx

.include <bsd.port.mk>
