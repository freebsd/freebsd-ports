# New ports collection makefile for:   adabroker
# Date created:         17 Apr 2000
# Whom:                 Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	adabroker
PORTVERSION=	1.0p3
CATEGORIES=	devel
MASTER_SITES=	http://adabroker.eu.org/distrib/
DISTNAME=	adabroker-1.0pre3

MAINTAINER=	sam@inf.enst.fr

BUILD_DEPENDS=	adagcc:${PORTSDIR}/lang/gnat
LIB_DEPENDS=	adasockets.0:${PORTSDIR}/net/adasockets

USE_AUTOCONF=	yes
USE_AUTOMAKE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--enable-adasockets

post-install:
	${RM} ${PREFIX}/lib/adabroker/allsrc.adb
	${LDCONFIG} -m ${PREFIX}/lib

MAN1=		ab_names.1 ab_gnome.1
MAN7=		adabroker.7

.include <bsd.port.mk>
