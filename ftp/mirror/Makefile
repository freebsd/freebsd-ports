# New ports collection makefile for:	mirror
# Version required:	2.9
# Date created:		15 May 1995
# Whom:			torstenb
#
# $Id: Makefile,v 1.9 1999/01/02 00:12:20 asami Exp $
#

DISTNAME=	mirror-2.9
CATEGORIES=	ftp
MASTER_SITES=	ftp://src.doc.ic.ac.uk/computing/archiving/mirror/

MAINTAINER=	torstenb@FreeBSD.ORG

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAN1=		mirror.1 mirror-master.1


pre-install:
	${MKDIR} ${PREFIX}/lib/mirror

.include <bsd.port.mk>
