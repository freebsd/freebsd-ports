# New ports collection makefile for:	klog
# Date created:		2004-07-05
# Whom:			Matt Dawson <matt@mattsnetwork.co.uk>
#
# $FreeBSD$

PORTNAME=	klog
PORTVERSION=	0.2.8
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://download.berlios.de/klog/

MAINTAINER=	matt@mattsnetwork.co.uk
COMMENT=	ADIF compatible logging application

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

.include <bsd.port.post.mk>
