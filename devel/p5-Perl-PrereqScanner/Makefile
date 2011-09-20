# New ports collection makefile for:	devel/p5-Perl-PrereqScanner
# Date created:				2011-09-19
# Whom:					Geraud CONTINSOUZAS <geraud@gcu.info>
#
# $FreeBSD$
#

PORTNAME=	Perl-PrereqScanner
PORTVERSION=	1.007
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
# MASTER_SITE_SUBDIR=	CPAN:JQUELIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	geraud@gcu.info
COMMENT=	A tool to scan your Perl code for its prerequisites

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-PPI>=0:${PORTSDIR}/textproc/p5-PPI \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Params-Util>=0:${PORTSDIR}/devel/p5-Params-Util \
		p5-String-RewritePrefix>=0:${PORTSDIR}/textproc/p5-String-RewritePrefix \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	scan_prereqs.1
MAN3=	Perl::PrereqScanner.3 \
	Perl::PrereqScanner::Scanner.3 \
	Perl::PrereqScanner::Scanner::Aliased.3 \
	Perl::PrereqScanner::Scanner::Moose.3 \
	Perl::PrereqScanner::Scanner::POE.3 \
	Perl::PrereqScanner::Scanner::Perl5.3 \
	Perl::PrereqScanner::Scanner::TestMore.3 \

.include <bsd.port.mk>
