# New ports collection makefile for:	kbilliards
# Date created:				15 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	kbilliards
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	games kde
MASTER_SITES=	http://www.hostnotfound.it/kbilliards/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Funny billiards simulator game for KDE

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_BZIP2=	yes
USE_KDELIBS_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
