# New ports collection makefile for:	zircon
# Version required:	1.18.91
# Date created:		19 Aug 1995
# Whom:			jkh / pst
#
# $Id: Makefile,v 1.23 1998/02/10 02:11:11 jseger Exp $
#

DISTNAME=	zircon-1.18.91
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
