# New ports collection makefile for:	pgperl
# Date created:		22 December 1996
# Whom:			jmz
#
# $FreeBSD$
#

PORTNAME=	pgperl
PORTVERSION=	2.17
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PGPLOT
DISTNAME=	PGPLOT-${PORTVERSION}

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	A perl5 extension which makes available the pgplot library

LIB_DEPENDS=	pgplot.5:${PORTSDIR}/graphics/pgplot
BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/ExtUtils/F77.pm:${PORTSDIR}/lang/p5-F77

BROKEN=		Incorrectly installs a perllocal.pod file

USE_PERL5=	yes
ALL_TARGET=	dynamic
SCRIPTS_ENV=	PERL=${PERL}

.include <bsd.port.pre.mk>

MAN3=	PGPLOT.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-install:
	@${MKDIR} ${PREFIX}/share/doc/pgperl
	@(cd ${WRKSRC}; ${INSTALL_DATA} LICENSE test* \
		${PREFIX}/share/doc/pgperl)

.include <bsd.port.post.mk>
