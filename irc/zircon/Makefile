# New ports collection makefile for:	zircon
# Version required:	1.18.213
# Date created:		19 Aug 1995
# Whom:			jkh / pst
#
# $Id: Makefile,v 1.37 1999/02/22 03:20:03 steve Exp $
#

DISTNAME=	zircon-1.18.213
CATEGORIES=	net tk80
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/ \
		ftp://ftp.dinoex.sub.org/pub/approved/

MAINTAINER=	jseger@FreeBSD.org

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

IS_INTERACTIVE=	yes
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC} && ./installZircon)

.include <bsd.port.mk>
