# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	File-Tail-Scribe
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gaod@hychen.org
COMMENT=	Perl Module to tail file to Scribe server

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-Tail-Dir>=0:devel/p5-File-Tail-Dir \
		p5-Log-Dispatch-Scribe>=0:devel/p5-Log-Dispatch-Scribe \
		p5-Moose>=0:devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockObject>=0:devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
