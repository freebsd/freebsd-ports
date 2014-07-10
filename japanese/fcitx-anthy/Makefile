# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-anthy
PORTVERSION=	0.1.1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anthy support for Fcitx

LIB_DEPENDS=	libfcitx-config.so:${PORTSDIR}/chinese/fcitx \
		libanthy.so:${PORTSDIR}/japanese/anthy

USES=		cmake gettext pkgconfig tar:xz
USE_GNOME=	intltool

PROJECTHOST=	fcitx

.include <bsd.port.mk>
