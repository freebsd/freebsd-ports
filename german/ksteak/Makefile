# New ports collection makefile for:	ksteak
# Date created:		2003/02/16
# Whom:			Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	ksteak
PORTVERSION=	1.0.0.p2
PORTREVISION=	6
CATEGORIES=	german kde
MASTER_SITES=	http://www.der-fritz.de/ksteak/
DISTNAME=	ksteak-1.0.0pre2

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	KDE frontend for steak, an english - german dictionary

RUN_DEPENDS=	steak:${PORTSDIR}/german/steak

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>
EXTRA_PATCHES=	${PORTSDIR}/x11/kde3/files/extrapatch-old_configure
.include <bsd.port.post.mk>
