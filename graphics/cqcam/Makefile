# New ports collection makefile for:	cqcam
# Version required:	0.45a
# Date created:		29 Oct 1997
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $Id: Makefile,v 1.8 1998/11/29 13:47:11 asami Exp $
#

DISTNAME=	cqcam-0.45a
CATEGORIES=	graphics tk80
MASTER_SITES=	http://www.cs.virginia.edu/~patrick/cqcam/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80 \
		jpeg.9:${PORTSDIR}/graphics/jpeg

ONLY_FOR_ARCHS=	i386

MAN1=		cqcam.1
MLINKS=		cqcam.1 webcam.1 \
		cqcam.1 xcqcam.1

.include <bsd.port.mk>
