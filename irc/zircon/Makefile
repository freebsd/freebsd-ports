# New ports collection makefile for:	zircon
# Version required:	1.18.171
# Date created:		19 Aug 1995
# Whom:			jkh / pst
#
# $Id: Makefile,v 1.33 1998/09/29 17:24:24 jkh Exp $
#

DISTNAME=	zircon-1.18.180
CATEGORIES=	net tk81
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	jseger@FreeBSD.org

BROKEN="fetch, distfile not avail. - need to update to zircon-1.18.201.tar.gz"

BUILD_DEPENDS=	wish8.1:${PORTSDIR}/x11-toolkits/tk81
RUN_DEPENDS=	wish8.1:${PORTSDIR}/x11-toolkits/tk81

IS_INTERACTIVE=	yes
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC} && ./installZircon)

.include <bsd.port.mk>
