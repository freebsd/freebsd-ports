# New ports collection makefile for:	Perl::Metrics::Lite
# Date created:		31 Dec 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Perl-Metrics-Lite
PORTVERSION=	0.061
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for pluggable Perl Code Metrics System

RUN_DEPENDS=	\
	p5-PPI>=1.113:${PORTSDIR}/textproc/p5-PPI \
	p5-Readonly>=1.03:${PORTSDIR}/devel/p5-Readonly \
	p5-Text-ASCIITable>0:${PORTSDIR}/textproc/p5-Text-ASCIITable
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	measureperl-checkstyle.1 \
	measureperl.1
MAN3=	Perl::Metrics::Lite.3 \
	Perl::Metrics::Lite::Analysis.3 \
	Perl::Metrics::Lite::Analysis::Util.3 \
	Perl::Metrics::Lite::FileFinder.3

.include <bsd.port.mk>
