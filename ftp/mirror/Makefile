# New ports collection makefile for:	mirror
# Date created:		15 May 1995
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	mirror
PORTVERSION=	2.9
CATEGORIES=	ftp

MASTER_SITES=	ftp://sunsite.org.uk/packages/mirror/ \
		ftp://src.doc.ic.ac.uk/computing/archiving/mirror/ \
		ftp://ftp.cs.columbia.edu/archives/perl/mirror/ \
		ftp://giswitch.sggw.waw.pl/pub/unix/mirror/ \
		ftp://SunSITE.tus.ac.jp/pub/archives/packages/mirror/
PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	ftp.pl_wupatch

MAINTAINER=	ryan@sasknow.com

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAN1=		mirror.1 mirror-master.1

pre-install:
	@${MKDIR} ${PREFIX}/lib/mirror

.include <bsd.port.mk>
