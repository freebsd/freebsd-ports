# New ports collection makefile for:	kpp
# Date created:		19 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kpp
PORTVERSION=	0.16d
CATEGORIES=	devel
MASTER_SITES=	http://www.msoe.edu/~geiseri/files/

MAINTAINER=	ports@FreeBSD.org

USE_KDELIBS_VER=1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--datadir=${PREFIX}
CONFIGURE_ENV=	KDEDIR="${PREFIX}"

.include <bsd.port.mk>
