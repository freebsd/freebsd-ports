# New ports collection makefile for:	p5-Tree-Node
# Date created: 			01 July 2005
# Whom: 				Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Tree-Node
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tree
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Memory-efficient tree nodes in Perl

BUILD_DEPENDS+=	${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		${SITE_PERL}/${PERL_ARCH}/Devel/Leak.pm:${PORTSDIR}/devel/p5-Devel-Leak \
		${SITE_PERL}/Test/Portability/Files.pm:${PORTSDIR}/devel/p5-Test-Portability-Files
RUN_DEPENDS+=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=		Tree::Node.3

.include <bsd.port.mk>
