# New ports collection makefile for:   adabroker
# Date created:         17 Apr 2000
# Whom:                 Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	adabroker
PORTVERSION=	1.0p4
CATEGORIES=	devel
MASTER_SITES=	http://adabroker.eu.org/distrib/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/pre/}

MAINTAINER=	sam@inf.enst.fr

BUILD_DEPENDS=	adagcc:${PORTSDIR}/lang/gnat
LIB_DEPENDS=	adasockets.0:${PORTSDIR}/net/adasockets

USE_LIBTOOL=	yes
USE_AUTOMAKE_VER=14
CONFIGURE_ARGS=	--enable-adasockets
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=	ab_names.1 ab_gnome.1
MAN7=	adabroker.7

post-install:
	${RM} ${PREFIX}/lib/adabroker/allsrc.adb

.include <bsd.port.mk>
