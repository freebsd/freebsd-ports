# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-DNS-Lite
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pure-Perl DNS resolver with support for timeout

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils
TEST_DEPENDS=	p5-Cache-LRU>=0:devel/p5-Cache-LRU \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
