# New ports collection makefile for:	fcitx-libpinyin
# Date created:				7 Apr 2012
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fcitx-libpinyin
PORTVERSION=	0.2.0
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://cloud.github.com/downloads/fcitx/fcitx-libpinyin/:libpinyin
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} model.text.tar.gz:libpinyin
DIST_SUBDIR=	fcitx
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	lichray@gmail.com
COMMENT=	The libpinyin support for Fcitx

LIB_DEPENDS=	fcitx-config.4:${PORTSDIR}/chinese/fcitx \
		pinyin.2:${PORTSDIR}/chinese/libpinyin

USE_LDCONFIG=	${PREFIX}/lib/fcitx/
USE_XZ=		yes
USE_GETTEXT=	yes
USE_CMAKE=	yes
USE_GNOME=	intltool
INSTALLS_ICONS=	yes

post-patch:
	@${LN} -s ${_DISTDIR}/model.text.tar.gz ${WRKSRC}/data

PROJECTHOST=	fcitx

.include <bsd.port.mk>
