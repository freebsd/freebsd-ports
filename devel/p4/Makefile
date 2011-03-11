# New ports collection makefile for:	p4
# Date created:				3 Apr 2010
# Whom:					gordon@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	p4
PORTVERSION=	2010.2.279478
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/ \
		http://filehost.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/
DISTNAME=	p4
EXTRACT_SUFX=
EXTRACT_ONLY=	# none

MAINTAINER=	gordon@FreeBSD.org
COMMENT=	Perforce client

ONLY_FOR_ARCHS=	amd64 i386 sparc64

P4VERSION=	r${PORTVERSION:S/^20//:C/\.[0-9]+$//}
DIST_SUBDIR=	perforce/${PORTVERSION}/bin.${PLATFORM}
DISTINFO_FILE=	${MASTERDIR}/distinfo.${PLATFORM}

RESTRICTED=	Restricted distribution

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/p4

.include <bsd.port.pre.mk>

.include "Makefile.inc"

do-install:
	${INSTALL_PROGRAM} ${_DISTDIR}/p4 ${PREFIX}/bin/

.include <bsd.port.post.mk>
