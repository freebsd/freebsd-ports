# -*-mode: makefile-*-
# New ports collection makefile for:	koffice
# Date created:				Sun May 14 2000 16:33:15
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koffice
PORTVERSION=	1.3.2
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
		wv2:${PORTSDIR}/textproc/wv2 \
		xml2:${PORTSDIR}/textproc/libxml2 \
		xslt:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	wn:${PORTSDIR}/textproc/wordnet

USE_KDELIBS_VER=	3
PREFIX=			${KDE_PREFIX}

USE_BZIP2=		yes
USE_GMAKE=		yes
USE_ICONV=		yes
USE_PYTHON=		yes
GNU_CONFIGURE=		yes

INSTALLS_SHLIB=		yes
LDCONFIG_DIRS+=		%%PREFIX%%/lib %%PREFIX%%/lib/kde3

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.mk>
