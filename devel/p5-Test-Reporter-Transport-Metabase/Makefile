# New ports collection makefile for:	p5-Test-Reporter-Transport-Metabase
# Date created:		2011-02-05
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Reporter-Transport-Metabase
PORTVERSION=	1.999008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DA/DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Metabase transport for Test::Reporter

BUILD_DEPENDS=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Config-Perl-V>0:${PORTSDIR}/devel/p5-Config-Perl-V \
		p5-CPAN-Testers-Report>0:${PORTSDIR}/devel/p5-CPAN-Testers-Report \
		p5-Metabase-Fact>0:${PORTSDIR}/devel/p5-Metabase-Fact \
		p5-Metabase-Client-Simple>0:${PORTSDIR}/devel/p5-Metabase-Client-Simple \
		p5-Test-Reporter>>1.54:${PORTSDIR}/devel/p5-Test-Reporter
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::Reporter::Transport::Metabase.3

.include <bsd.port.mk>
