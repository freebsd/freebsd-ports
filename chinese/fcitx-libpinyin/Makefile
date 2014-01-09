# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-libpinyin
PORTVERSION=	0.2.1
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://cloud.github.com/downloads/fcitx/fcitx-libpinyin/:libpinyin
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} model.text.${MDVER}.tar.gz:libpinyin
DIST_SUBDIR=	fcitx
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	lichray@gmail.com
COMMENT=	The libpinyin support for Fcitx

LIB_DEPENDS=	libfcitx-config.so:${PORTSDIR}/chinese/fcitx \
		libpinyin.so:${PORTSDIR}/chinese/libpinyin

USE_LDCONFIG=	${PREFIX}/lib/fcitx/
USE_XZ=		yes
USES=		cmake gettext pkgconfig
USE_GNOME=	intltool
INSTALLS_ICONS=	yes

post-patch:
	@${LN} -s ${_DISTDIR}/model.text.${MDVER}.tar.gz ${WRKSRC}/data

PROJECTHOST=	fcitx
MDVER=		20120921

.include <bsd.port.mk>
