# New ports collection Makefile for:	kfreerings
# Date created:				2004-02-13
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	kfreerings
PORTVERSION=	1.0.b.1
PORTREVISION=	1
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kfreerings
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b./beta/}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	A small puzzle game

USE_KDELIBS_VER=3
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
