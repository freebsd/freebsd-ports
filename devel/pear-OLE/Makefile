# Ports collection makefile for:  pear-OLE
# Date created:			  16 March 2004
# Whom:				  Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	OLE
PORTVERSION=	0.5
CATEGORIES=	devel www pear

MAINTAINER=	pav@FreeBSD.org
COMMENT=	PEAR class for reading and writing OLE containers

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	OLE
FILES=		OLE.php PPS.php PPS/File.php PPS/Root.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
