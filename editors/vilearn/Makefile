# New ports collection makefile for:	vilearn
# Version required:	1.0
# Date created:		12 Dec 1997
# Whom:			Ian Vaudrey <i.vaudrey@bigfoot.com>
#
# $FreeBSD$
#

DISTNAME=	vilearn
PKGNAME=	vilearn-1.0
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.funet.fi/pub/Linux/util/networking/util-swan/pub/misc/ \
		ftp://ftp.mcc.ac.uk/pub/linux/fi.mirror/util/networking/util-swan/pub/misc/ \
		ftp://ftp.tu-chemnitz.de/pub/linux/funet-mirror/util/networking/util-swan/pub/misc/
EXTRACT_SUFX=	.Z

MAINTAINER=	i.vaudrey@bigfoot.com

WRKSRC=		${WRKDIR}/${PKGNAME}
EXTRACT_CMD=	uncompress
EXTRACT_BEFORE_ARGS=	-c
EXTRACT_AFTER_ARGS=	| tail -n 1759 | sh

MAN1=		vilearn.1

.include <bsd.port.mk>
