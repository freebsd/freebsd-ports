# Created by: gordon@FreeBSD.org
# $FreeBSD$

PORTNAME=	p4
PORTVERSION=	2015.1.1384697
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/ \
		http://filehost.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/
DISTNAME=	p4
EXTRACT_SUFX=
EXTRACT_ONLY=	# none

MAINTAINER=	gordon@FreeBSD.org
COMMENT=	Perforce client

RESTRICTED=	Restricted distribution

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/p4

.include <bsd.port.pre.mk>

.include "Makefile.inc"

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/p4 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
