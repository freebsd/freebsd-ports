# New ports collection makefile for:	zircon
# Version required:	1.18.210
# Date created:		19 Aug 1995
# Whom:			jkh / pst
#
# $Id: Makefile,v 1.35 1999/01/26 02:58:39 steve Exp $
#

DISTNAME=	zircon-1.18.210
CATEGORIES=	net tk81
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/ \
		ftp://ftp.dinoex.sub.org/pub/approved/

MAINTAINER=	jseger@FreeBSD.org

BUILD_DEPENDS=	wish8.1:${PORTSDIR}/x11-toolkits/tk81
RUN_DEPENDS=	wish8.1:${PORTSDIR}/x11-toolkits/tk81

IS_INTERACTIVE=	yes
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC} && ./installZircon)

.include <bsd.port.mk>
