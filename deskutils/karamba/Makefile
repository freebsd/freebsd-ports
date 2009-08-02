# New ports collection makefile for:	karamba
# Date created:		9 April 2003
# Whom:			Scott A. Moberly
#
# $FreeBSD$

PORTNAME=	karamba
PORTVERSION=	0.17
PORTREVISION=	8
CATEGORIES=	deskutils
MASTER_SITES=	http://www.efd.lth.se/~d98hk/karamba/src/

MAINTAINER=	smoberly@karamazov.org
COMMENT=	Display various information right on your desktop

EXTRA_PATCHES=	${.CURDIR}/../../comms/kallers/files/patch-configure

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

.include <bsd.port.mk>
