# New ports collection makefile for:	zircon
# Version required:	1.18.31
# Date created:		19 Aug 1995
# Whom:			jkh / pst
#
# $Id: Makefile,v 1.18 1997/10/01 21:01:25 jkh Exp $
#

DISTNAME=	zircon-1.18.71
CATEGORIES=	net tk80
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	ports@FreeBSD.org

IS_INTERACTIVE=	yes
NO_BUILD=	yes

BUILD_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80
RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80

do-install:
	(cd ${WRKSRC} && ./installZircon)

.include <bsd.port.mk>
