# New ports collection makefile for:	ksteak
# Date created:		2003/02/16
# Whom:			Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	ksteak
PORTVERSION=	1.0.0.p2
PORTREVISION=	1
CATEGORIES=	german kde
MASTER_SITES=	http://www.der-fritz.de/ksteak/
DISTNAME=	ksteak-1.0.0pre2

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	KDE frontend for steak, an english - german dictionary

RUN_DEPENDS=	steak:${PORTSDIR}/german/steak

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>
EXTRA_PATCHES=	${PORTSDIR}/x11/kde3/files/extrapatch-old_configure
.include <bsd.port.post.mk>
