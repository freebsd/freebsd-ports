# New ports collection makefile for:	p5-CPAN-Checksums
# Date created:				September 21st 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	CPAN-Checksums
PORTVERSION=	2.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl module to write a CHECKSUMS file for a directory as on CPAN

BUILD_DEPENDS=	${SITE_PERL}/Data/Compare.pm:${PORTSDIR}/devel/p5-Data-Compare
RUN_DEPENDS=	${SITE_PERL}/Data/Compare.pm:${PORTSDIR}/devel/p5-Data-Compare

PERL_CONFIGURE=	YES

MAN3=		CPAN::Checksums.3

.include <bsd.port.mk>
