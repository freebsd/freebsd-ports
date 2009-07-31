# New ports collection makefile for:	devel/p5-Log-Accounting-SVK
# Date created:				21 Oct 2004
# Whom:					Yuan-Chung Hsiao <ychsiao@ychsiao.idv.tw>
#
# $FreeBSD$
#

PORTNAME=	Log-Accounting-SVK
PORTVERSION=	0.05
PORTREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Perl module for accounting SVK repository

BUILD_DEPENDS=	${SITE_PERL}/SVK.pm:${PORTSDIR}/devel/svk \
		${SITE_PERL}/Spiffy.pm:${PORTSDIR}/devel/p5-Spiffy \
		${SITE_PERL}/Graph/SocialMap.pm:${PORTSDIR}/graphics/p5-Graph-SocialMap \
		${SITE_PERL}/Graph/Writer/GraphViz.pm:${PORTSDIR}/graphics/p5-Graph-Writer-GraphViz \
		${SITE_PERL}/Algorithm/Accounting.pm:${PORTSDIR}/devel/p5-Algorithm-Accounting
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=	svk-accounting.pl.1 svk-developer-graph.pl.1
MAN3=	Log::Accounting::SVK.3

.include <bsd.port.mk>
