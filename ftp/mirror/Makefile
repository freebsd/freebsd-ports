# New ports collection makefile for:	mirror
# Date created:		15 May 1995
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	mirror
PORTVERSION=	2.9
CATEGORIES=	ftp
MASTER_SITES=	ftp://src.doc.ic.ac.uk/computing/archiving/mirror/

PATCH_SITES=	http://sunsite.org.uk/packages/mirror/
PATCHFILES=	ftp.pl_wupatch

MAINTAINER=	torstenb@FreeBSD.org

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAN1=		mirror.1 mirror-master.1

pre-install:
	${MKDIR} ${PREFIX}/lib/mirror

.include <bsd.port.mk>
