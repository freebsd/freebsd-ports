# New ports collection makefile for:	kpp
# Version required:	0.15c
# Date created:		19 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	kpp-0.15c
CATEGORIES=	devel
MASTER_SITES=	http://www.msoe.edu/~geiseri/files/

MAINTAINER=	andrews@technologist.com

LIB_DEPENDS=	kdeui.3:${PORTSDIR}/x11/kdelibs11

GNU_CONFIGURE=	yes
USE_QT=		yes
USE_NEWGCC=	yes
CONFIGURE_ARGS= --prefix=${PREFIX} --datadir=${PREFIX}
CONFIGURE_ENV=  KDEDIR="${PREFIX}"

.include <bsd.port.mk>
