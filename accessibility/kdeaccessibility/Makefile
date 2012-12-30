# New ports collection makefile for:	kdeaccessibility
# Date created:				19 Jan 2004 18:40:32 EST
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdeaccessibility
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	5
CATEGORIES=	accessibility kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Accessibility applications for KDE

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3

USE_XORG=	xtst
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-alsa=no

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>
