# New ports collection makefile for:	mirror
# Version required:	2.3
# Date created:		15 May 1995
# Whom:			torstenb
#
# $Id: Makefile,v 1.1.1.1 1995/05/19 07:23:13 asami Exp $
#

DISTNAME=	mirror-2.3
CATEGORIES+=	net
MASTER_SITES=	ftp://src.doc.ic.ac.uk/computing/archiving/mirror/

MAINTAINER=	torstenb@FreeBSD.ORG

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile

pre-install:
	mkdir -p ${PREFIX}/lib/mirror

.include <bsd.port.mk>
