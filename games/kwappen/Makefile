# New ports collection makefile for:	kwappen
# Date created:				2003-07-03
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kwappen
PORTVERSION=	1.1.5
PORTREVISION=	11
CATEGORIES=	games kde
MASTER_SITES=	http://www.lcs-chemie.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE board game

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_GETTEXT=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes

.include <bsd.port.mk>
