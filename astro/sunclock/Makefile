# ex:ts=8
# New ports collection makefile for:	sunclock
# Date created:		15 September 1996
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	sunclock
PORTVERSION=	3.45
CATEGORIES=	astro x11-clocks
MASTER_SITES=	ftp://ftp.ac-grenoble.fr/ge/geosciences/
EXTRACT_SUFX=	.tgz

MAINTAINER=	torstenb@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}v2

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_XPM=	YES
USE_IMAKE=	YES

MAN1=		sunclock.1

.include <bsd.port.mk>
