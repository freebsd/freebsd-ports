# New ports collection makefile for:	cqcam
# Date created:		29 Oct 1997
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	cqcam
PORTVERSION=	0.45a
CATEGORIES=	graphics tk82
MASTER_SITES=	ftp://ftp.cdrom.com/pub/unixfreeware/graphics/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82 \
		jpeg.9:${PORTSDIR}/graphics/jpeg

ONLY_FOR_ARCHS=	i386

MAN1=		cqcam.1
MLINKS=		cqcam.1 webcam.1 \
		cqcam.1 xcqcam.1

.include <bsd.port.mk>
