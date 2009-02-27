# New ports collection makefile for:	pgperl
# Date created:		22 December 1996
# Whom:			jmz
#
# $FreeBSD$
#

PORTNAME=	pgperl
PORTVERSION=	2.20
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/K/KG/KGB
DISTNAME=	PGPLOT-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl5 extension which makes available the pgplot library

LIB_DEPENDS=	pgplot.5:${PORTSDIR}/graphics/pgplot
BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/F77.pm:${PORTSDIR}/lang/p5-F77
USE_FORTRAN=	g77

MAN3=	PGPLOT.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

USE_PERL5=	yes
SCRIPTS_ENV=	PERL=${PERL}
INSTALL_TARGET=	pure_install

.include <bsd.port.pre.mk>

.ifndef(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}; ${INSTALL_DATA} LICENSE test* \
		${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
