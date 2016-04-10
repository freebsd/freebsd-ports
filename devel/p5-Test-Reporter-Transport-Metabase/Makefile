# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Reporter-Transport-Metabase
PORTVERSION=	1.999010
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Metabase transport for Test::Reporter

BUILD_DEPENDS=	p5-JSON>=0:converters/p5-JSON \
		p5-Config-Perl-V>0:devel/p5-Config-Perl-V \
		p5-CPAN-Testers-Report>0:devel/p5-CPAN-Testers-Report \
		p5-Metabase-Fact>0:devel/p5-Metabase-Fact \
		p5-Metabase-Client-Simple>0:devel/p5-Metabase-Client-Simple \
		p5-Test-Reporter>>1.54:devel/p5-Test-Reporter
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
