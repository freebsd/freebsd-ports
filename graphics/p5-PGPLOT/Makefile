# New ports collection makefile for:	pgperl
# Version required:     2.06
# Date created:		22 December 1996
# Whom:			jmz
#
# $Id: Makefile,v 1.12 1998/11/11 05:37:20 asami Exp $
#

DISTNAME=       PGPLOT-2.08
PKGNAME=	pgperl-2.08
CATEGORIES=     graphics perl5
MASTER_SITES=   ftp://ftp.ast.cam.ac.uk/pgperl/

MAINTAINER=	jmz@FreeBSD.org

LIB_DEPENDS=    pgplot.5:${PORTSDIR}/graphics/pgplot

USE_PERL5=	yes
ALL_TARGET=	dynamic
SCRIPTS_ENV=	PERL=${PERL}

.include <bsd.port.pre.mk>

MAN3=	ExtUtils::F77.3 PGPLOT.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-install:
	@${MKDIR} ${PREFIX}/share/doc/pgperl
	@(cd ${WRKSRC}; ${INSTALL_DATA} LICENSE test* \
		${PREFIX}/share/doc/pgperl)

.include <bsd.port.post.mk>
