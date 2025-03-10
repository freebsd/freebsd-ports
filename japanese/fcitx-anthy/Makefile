PORTNAME=	fcitx-anthy
DISTVERSION=	0.2.4
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

FLAVORS=	original unicode
FLAVOR?=	${FLAVORS:[1]}

USES=		cmake gettext gnome pkgconfig tar:xz

.if ${FLAVOR} == original
LIB_DEPENDS+=		libanthy.so:japanese/anthy
CONFLICTS_INSTALL=	${PORTNAME}-unicode
.else
PKGNAMESUFFIX=		-unicode
LIB_DEPENDS+=		libanthy-unicode.so:japanese/anthy-unicode
CONFLICTS_INSTALL=	${PORTNAME}
.endif

.include <bsd.port.mk>
