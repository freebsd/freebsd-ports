# ex:ts=8
# New ports collection makefile for:	sunclock
# Date created:		15 September 1996
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	sunclock
PORTVERSION=	3.50.p1
CATEGORIES=	astro x11-clocks
MASTER_SITES=	ftp://ftp.ac-grenoble.fr/ge/geosciences/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pat@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_IMAKE=	yes

MAN1=		sunclock.1

.include <bsd.port.mk>
