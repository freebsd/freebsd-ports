# -*-mode: makefile-*-
# New ports collection makefile for:	koffice
# Date created:				Sun May 14 2000 16:33:15
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koffice
PORTVERSION=	1.2.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}-${PORTVERSION}/src
DIST_SUBDIR=	KDE/koffice

PATCH_SITES=	http://www.fruitsalad.org/patches/
PATCHFILES=	1.2.1_kword_crashes.diff

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Office Suite for KDE3

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2

USE_KDELIBS_VER=	3
PREFIX=			${KDE_PREFIX}

USE_BZIP2=		yes
USE_GMAKE=		yes
USE_PYTHON=		yes
GNU_CONFIGURE=		yes

INSTALLS_SHLIB=		yes
LDCONFIG_DIRS+=		%%PREFIX%%/lib %%PREFIX%%/lib/kde3

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
