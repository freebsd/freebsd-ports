# New ports collection makefile for:	asmodem
# Date created:		11 May 1998
# Whom:			Sean Cole <scole@aracnet.com>
#
# $FreeBSD$
#

PORTNAME=	asmodem
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_AFTERSTEP}
MASTER_SITE_SUBDIR=	apps/asmodem
DISTNAME=	${PORTNAME}-0.6-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays the modem status, designed to match AfterStep

USE_IMAKE=	yes
USE_XORG=	xpm

MAN1=		asmodem.1
PLIST_FILES=	bin/asmodem

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
