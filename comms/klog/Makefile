# New ports collection makefile for:	klog
# Date created:		2004-07-05
# Whom:			Matt Dawson <matt@mattsnetwork.co.uk>
#
# $FreeBSD$

PORTNAME=	klog
PORTVERSION=	0.3.3
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	klog

MAINTAINER=	az@FreeBSD.org
COMMENT=	ADIF compatible logging application

LIB_DEPENDS=	hamlib:${PORTSDIR}/comms/hamlib

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_KDELIBS_VER=3

post-install:
	@${INSTALL_DATA}	${WRKSRC}/src/klog.desktop \
		 ${PREFIX}/share/applnk/Applications/klog.desktop

.include <bsd.port.mk>
