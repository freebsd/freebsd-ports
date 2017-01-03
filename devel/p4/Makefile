# Created by: gordon@FreeBSD.org
# $FreeBSD$

PORTNAME=	p4
PORTVERSION=	2016.1.1470074
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/ \
		http://filehost.perforce.com/perforce/${P4VERSION}/bin.${PLATFORM}/
DISTNAME=	p4
EXTRACT_SUFX=
EXTRACT_ONLY=	# none

MAINTAINER=	gordon@FreeBSD.org
COMMENT=	Perforce client

# The LICENSE file is not included in the distfile, but Catherine Louie of
# Perforce Support assures me that the LICENSE file on swarm also applies to
# the binary distribution.
# https://swarm.workshop.perforce.com/projects/perforce_software-p4/files/2016-1/LICENSE
LICENSE=	BSD2CLAUSE

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/p4

.include <bsd.port.pre.mk>

.include "Makefile.inc"

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/p4 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
