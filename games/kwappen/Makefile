# New ports collection makefile for:	kwappen
# Date created:				2003-07-03
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kwappen
PORTVERSION=	1.1.5
PORTREVISION=	7
CATEGORIES=	games kde
MASTER_SITES=	http://www.lcs-chemie.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE board game

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_GETTEXT=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes

.include <bsd.port.mk>
