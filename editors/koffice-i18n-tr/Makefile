# New ports collection makefile for:	koffice-i18n-tr
# Date created:                         27 April 2003
# Whom:                                 Michael Nottebrock <michaelnottebrock@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	koffice-i18n
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/koffice-${PORTVERSION}/src
PKGNAMEPREFIX=	tr-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Localized messages and documentation for koffice

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
KDE_I18N=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>
