# New ports collection makefile for:	mirror
# Version required:	2.8
# Date created:		15 May 1995
# Whom:			torstenb
#
# $Id: Makefile,v 1.5 1996/11/18 14:08:35 asami Exp $
#

DISTNAME=	mirror-2.8
CATEGORIES=	net
MASTER_SITES=	ftp://src.doc.ic.ac.uk/computing/archiving/mirror/

MAINTAINER=	torstenb@FreeBSD.ORG

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAN1=		mirror.1 mirrormaster.1

pre-install:
	${MKDIR} ${PREFIX}/lib/mirror

.include <bsd.port.mk>
