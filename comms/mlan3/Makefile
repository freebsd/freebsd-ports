# New ports collection makefile for:	mlan3
# Date created:				January 16, 2002
# Whom:					hm
#
# $FreeBSD$
#

PORTNAME=	mlan3
PORTVERSION=	1.00
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.dalsemi.com/pub/auto_id/public/
DISTNAME=	owpd300b

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Version 3.00 beta API for Dallas Semiconductors 1-wire lan devices

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_WRKSUBDIR=	yes
USE_ZIP=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not install (Makefiles need rework)"
.endif

.include <bsd.port.post.mk>
