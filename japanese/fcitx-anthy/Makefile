PORTNAME=	fcitx-anthy
DISTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Anthy support for Fcitx
WWW=		https://fcitx-im.org/wiki/Fcitx

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		fcitx:chinese/fcitx
LIB_DEPENDS=	libanthy-unicode.so:japanese/anthy-unicode

USES=		cmake gettext gnome pkgconfig tar:xz

.include <bsd.port.mk>
