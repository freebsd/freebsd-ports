# ex:ts=8
# New ports collection makefile for:	hanzim
# Date created:			Sep 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hanzim
PORTVERSION=	1.2
CATEGORIES=	chinese tk83
MASTER_SITES=	ftp://kommos.ucsd.edu/pub/arobert/Chinese/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A Chinese character learning-aid program

BUILD_DEPENDS+=	wish8.3:${PORTSDIR}/x11-toolkits/tk83
RUN_DEPENDS+=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

WRKSRC=		${WRKDIR}/Hanzim
ALL_TARGET=	# empty

MAN1=	hanzim.1

.include <bsd.port.mk>
