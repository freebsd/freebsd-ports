# New ports collection makefile for:	libffi-devel
# Date created:			28 Nov 2007
# Whom:				Björn König <bkoenig@alpha-tierchen.de
#
# $FreeBSD$
#

PORTNAME=	libffi
DISTVERSION=	2.0-20080208
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.alpha-tierchen.de/pub/FreeBSD/ports/distfiles/
PKGNAMESUFFIX=	-devel

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	Foreign Function Interface

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes

USE_BZIP2=	yes
USE_LDCONFIG=	yes
CONFLICTS=	gcc-3* libffi-[0-9]*

.include <bsd.port.mk>
