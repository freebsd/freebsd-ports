# New ports collection makefile for:	kmysqladmin
# Date created:			Aug 12, 2005
# Whom:				Igor Leonenko <bananaz@bk.ru>
#
# $FreeBSD$
#

PORTNAME=	kmysqladmin
PORTVERSION=	0.7.2
CATEGORIES=	databases
MASTER_SITES=	http://www.alwins-world.de/programs/download/kmysqladmin/

MAINTAINER=	bananaz@bk.ru
COMMENT=	A graphical frontend for administration of mysql servers

USE_AUTOTOOLS=	libtool:15
USE_MYSQL=	yes
USE_XLIB=	yes
USE_QT_VER=	3
USE_KDELIBS_VER=3

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"don't build on 4.x"
.endif

.include <bsd.port.post.mk>
