# New ports collection makefile for:	pgperl
# Version required:     1.0
# Date created:		22 December 1996
# Whom:			jmz
#
# $Id$
#

DISTNAME=       PGPLOT1.0b_src
EXTRACT_SUFX=	.tar.Z
PKGNAME=	pgperl-1.0
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.ast.cam.ac.uk/pgperl/perl5/

WRKSRC=		${WRKDIR}/PGPLOT
ALL_TARGET=	dynamic

MAINTAINER=	jmz@FreeBSD.org

BUILD_DEPENDS=  perl5.003
LIB_DEPENDS=    pgplot\\.5\\.
RUN_DEPENDS=    perl5.003

post-install:
	@mkdir -p ${PREFIX}/share/pgperl
	@(cd ${WRKSRC}; cp LICENSE pgperl.doc testpg* ${PREFIX}/share/pgperl)

.include <bsd.port.mk>
