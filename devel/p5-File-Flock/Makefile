# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-Flock
PORTVERSION=	2014.01
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for file locking with flock

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-Data-Structure-Util>=0:devel/p5-Data-Structure-Util \
		p5-IO-Event>=0.812:devel/p5-IO-Event
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Test-SharedFork>=0:devel/p5-Test-SharedFork

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
