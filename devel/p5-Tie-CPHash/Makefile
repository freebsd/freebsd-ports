# New ports collection makefile for:	Tie-CPHash
# Date created:			09 October 2006
# Whom:				David Chaplin-Loebell <direct@klatha.com>
#
# $FreeBSD$
#

PORTNAME=	Tie-CPHash
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	direct@klatha.com
COMMENT=	Perl module implementing a case preserving hash table

BUILD_DEPENDS=	p5-ExtUtils-MakeMaker>=0:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

PERL_MODBUILD=	yes

MAN3=		Tie::CPHash.3

.include <bsd.port.mk>
