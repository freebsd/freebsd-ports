# New ports collection makefile for:	platero
# Date created:			Tue Jul  1 18:03:44 CEST 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		kalbum
PORTVERSION=		0.8.0
CATEGORIES=		graphics kde
MASTER_SITES=		http://www.paldandy.com/kalbum/data/${PORTNAME}-${PORTVERSION}/

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		Create albums from a collection of images

USE_KDELIBS_VER=	3
USE_BZIP2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
