# -*-mode: makefile-*-
# New ports collection makefile for:	koffice
# Date created:				Sun May 14 2000 16:33:15
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koffice
PORTVERSION=	1.3
PORTEPOCH=	1
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}-${PORTVERSION}/src
DIST_SUBDIR=	KDE/koffice

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Office Suite for KDE3

BUILD_DEPENDS=	Magick-config:${PORTSDIR}/graphics/ImageMagick \
		dot:${PORTSDIR}/graphics/graphviz
LIB_DEPENDS=	art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2 \
		aspell:${PORTSDIR}/textproc/aspell \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2 \
		paper.2:${PORTSDIR}/print/libpaper \
		xml2:${PORTSDIR}/textproc/libxml2 \
		xslt:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	wn:${PORTSDIR}/textproc/wordnet

USE_KDELIBS_VER=	3
PREFIX=			${KDE_PREFIX}

KDE_BUILD_PLIST=	yes
USE_BZIP2=		yes
USE_GMAKE=		yes
USE_ICONV=		yes
USE_PYTHON=		yes
GNU_CONFIGURE=		yes

INSTALLS_SHLIB=		yes
LDCONFIG_DIRS+=		%%PREFIX%%/lib %%PREFIX%%/lib/kde3

OPTIONS=		WV2 "Build with Microsoft Word import filter" off

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if defined(WITH_WV2)
LIB_DEPENDS+=	wv2:${PORTSDIR}/textproc/wv2
PLIST_APPEND+=	plist.wv2
.elseif defined(WITHOUT_WV2)
CONFIGURE_ARGS+=--without-libwv2
.endif

.include <bsd.port.post.mk>
