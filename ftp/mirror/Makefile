# New ports collection makefile for:	mirror
# Version required:	2.8
# Date created:		15 May 1995
# Whom:			torstenb
#
# $Id: Makefile,v 1.4 1996/11/18 11:35:24 asami Exp $
#

DISTNAME=	mirror-2.8
CATEGORIES=	net
MASTER_SITES=	ftp://src.doc.ic.ac.uk/computing/archiving/mirror/

MAINTAINER=	torstenb@FreeBSD.ORG

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAN1=		mirror.1 mirrormaster.1

pre-install:
	mkdir -p ${PREFIX}/lib/mirror

.include <bsd.port.mk>
