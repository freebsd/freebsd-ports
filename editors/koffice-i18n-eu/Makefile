# New ports collection makefile for:	koffice-i18n-eu
# Date created:                         20 October 2005
# Whom:                                 Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	koffice-i18n
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES?=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/koffice-${PORTVERSION}/src/koffice-l10n
PKGNAMEPREFIX=	eu-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basque messages and documentation for koffice

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
KDE_I18N=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>
