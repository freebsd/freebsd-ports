# New ports collection makefile for:	landscape
# Date created:				1 May 2001
# Whom:					Jonathan Belson <jon@witchspace.com>
#
# $FreeBSD$
#

PORTNAME=	landscape
PORTVERSION=	0.5.1
CATEGORIES=	graphics kde
MASTER_SITES=	http://www.dookie.demon.co.uk/

MAINTAINER=	jon@witchspace.com

LIB_DEPENDS=	pth.14:${PORTSDIR}/devel/pth

USE_MESA=	yes
USE_QT_VER=	2
USE_KDELIBS_VER=	2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/landscape ${PREFIX}/bin

.include <bsd.port.mk>
