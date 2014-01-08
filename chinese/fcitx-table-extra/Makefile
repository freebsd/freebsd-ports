# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-table-extra
PORTVERSION=	0.3.3
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Table-based input methods for Fcitx

LIB_DEPENDS=	libfcitx-config.so:${PORTSDIR}/chinese/fcitx

USE_XZ=		yes
USES=		cmake gettext
USE_GNOME=	intltool
INSTALLS_ICONS=	yes
STRIP=

PROJECTHOST=	fcitx

.include <bsd.port.mk>
