# New ports collection makefile for:	zircon
# Version required:	1.18.126
# Date created:		19 Aug 1995
# Whom:			jkh / pst
#
# $Id: Makefile,v 1.27 1998/04/11 02:29:14 jseger Exp $
#

DISTNAME=	zircon-1.18.126
CATEGORIES=	net tk80
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	jseger@FreeBSD.org

BUILD_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80
RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80

IS_INTERACTIVE=	yes
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC} && ./installZircon)

.include <bsd.port.mk>
