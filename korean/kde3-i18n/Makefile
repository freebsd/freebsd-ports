# New ports collection makefile for:    kde3-i18n-ko
# Date created:                         05 April 2002
# Whom:                                 Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	kde-i18n
PORTVERSION=	3.0.5
PORTREVISION=	1
CATEGORIES?=	korean kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	Attic/${PORTVERSION}a/src/kde-i18n
PKGNAMEPREFIX=	ko-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Korean messages and documentation for KDE3

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
KDE_I18N=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PKGNAMEPREFIX:S/-//}

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>
