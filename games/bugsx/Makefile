# New ports collection makefile for:  bugsx
# Version required:  1.08
# Date created:  7 December 1997
# Whom:  Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id: Makefile,v 1.2 1998/09/28 02:05:15 steve Exp $
#

DISTNAME=	bugsx108
PKGNAME=	bugsx-1.08
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications
EXTRACT_SUFX=	.tgz

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/bugsx
# isn't really gzipped
EXTRACT_CMD=		${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty
MAN1=		bugsx.1

post-install:
	strip ${PREFIX}/bin/bugsx

.include <bsd.port.mk>
