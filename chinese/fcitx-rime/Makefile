# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-rime
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	GOOGLE_CODE
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	RIME support for Fcitx

LIB_DEPENDS=	fcitx-config:${PORTSDIR}/chinese/fcitx \
		rime:${PORTSDIR}/chinese/librime

USE_LDCONFIG=	${PREFIX}/lib/fcitx/
USE_XZ=		yes
USES=		cmake gettext
USE_GNOME=	intltool
INSTALLS_ICONS=	yes

PROJECTHOST=	fcitx

NO_STAGE=	yes
.include <bsd.port.mk>
