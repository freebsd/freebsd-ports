# New ports collection makefile for:	tkgate
# Version required:			0.9
# Date created:				28 May 1999
# Whom:					Jeffery Hansen <hansen@cmu.edu>
#
# $Id$
#

DISTNAME=		tkgate-0.9
CATEGORIES=		cad
MASTER_SITES=		http://www.cs.cmu.edu/~hansen/tkgate/
EXTRACT_SUFX=		.tgz

MAINTAINER=		hansen@cmu.edu

LIB_DEPENDS=		tk80.1:${PORTSDIR}/x11-toolkits/tk80

USE_IMAKE=		yes
# Need to fix PREFIX brokenness in config.h.
PREFIX=			/usr/local

.include <bsd.port.mk>
