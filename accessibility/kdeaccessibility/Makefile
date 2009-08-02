# New ports collection makefile for:	kdeaccessibility
# Date created:				19 Jan 2004 18:40:32 EST
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdeaccessibility
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	2
CATEGORIES=	accessibility kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accessibility applications for KDE

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_XORG=	xtst
USE_BZIP2=	yes
USE_AUTOTOOLS=  libtool:22
USE_GMAKE=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>
