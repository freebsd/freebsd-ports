# New ports collection makefile for:	mirror
# Date created:		15 May 1995
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	mirror
PORTVERSION=	2.9
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	ftp://sunsite.org.uk/old-sunsite/mirror/ \
		ftp://src.doc.ic.ac.uk/old-sunsite/mirror/ \
		ftp://ftp.cs.columbia.edu/archives/perl/mirror/ \
		ftp://SunSITE.tus.ac.jp/pub/archives/packages/mirror/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	ftp.pl_wupatch

MAINTAINER=	ryan@sasknow.com
COMMENT=	Mirror packages on remote sites

PLIST_FILES=	bin/mirror \
		bin/do_unlinks \
		bin/pkgs_to_mmin \
		bin/mirror-master \
		lib/mirror/lchat.pl \
		lib/mirror/dateconv.pl \
		lib/mirror/ftp.pl \
		lib/mirror/lsparse.pl \
		lib/mirror/mirror.defaults.sample

PLIST_DIRS=	lib/mirror

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAN1=		mirror.1 mirror-master.1

pre-install:
	@${MKDIR} ${PREFIX}/lib/mirror

.include <bsd.port.mk>
