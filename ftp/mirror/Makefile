# New ports collection makefile for:	mirror
# Version required:	2.9
# Date created:		15 May 1995
# Whom:			torstenb
#
# $Id: Makefile,v 1.7 1998/06/08 12:41:12 torstenb Exp $
#

DISTNAME=	mirror-2.9
CATEGORIES=	net
MASTER_SITES=	ftp://src.doc.ic.ac.uk/computing/archiving/mirror/

MAINTAINER=	torstenb@FreeBSD.ORG

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAN1=		mirror.1 mirror-master.1

RUN_DEPENDS=	perl5:${PORTSDIR}/lang/perl5

pre-install:
	${MKDIR} ${PREFIX}/lib/mirror

.include <bsd.port.mk>
