# New ports collection makefile for:	landscape
# Date created:			1 May 2001
# Whom:				jon@witchspace.com
#
# $FreeBSD$
#

PORTNAME=		landscape
PORTVERSION=		0.5.1
PORTREVISION=		1
CATEGORIES=     	graphics kde
MASTER_SITES=		http://www.dookie.demon.co.uk/

MAINTAINER=		jon@witchspace.com

LIB_DEPENDS=    	pth.14:${PORTSDIR}/devel/pth

USE_MESA=		yes
USE_KDELIBS_VER=	2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/landscape ${PREFIX}/bin

post-install:
	strip ${PREFIX}/bin/landscape

.include <bsd.port.mk>
