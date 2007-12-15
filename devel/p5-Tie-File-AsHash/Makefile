# New ports collection makefile for:	p5-Tie-File-AsHash
# Date created:				13 December 2007
# Whom:	      				Ruben de Groot <rdg@bzerk.org>
#
# $FreeBSD$
#

PORTNAME=	Tie-File-AsHash
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Tie
PKGNAMEPREFIX=	p5-

MAINTAINER=	rdg@bzerk.org
COMMENT=	Access the lines of a disk file via a Perl hash

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${SITE_PERL}/Tie/File.pm:${PORTSDIR}/devel/p5-Tie-File

PERL_CONFIGURE=	yes

MAN3=		Tie::File::AsHash.3

.include <bsd.port.mk>
