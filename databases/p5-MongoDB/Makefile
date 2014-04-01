# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MongoDB
PORTVERSION=	0.702.2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FRIEDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mongo Driver for Perl

LICENSE=	APACHE20

BUILD_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Class-Method-Modifiers>=0:${PORTSDIR}/devel/p5-Class-Method-Modifiers \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-boolean>=0:${PORTSDIR}/devel/p5-boolean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Data-Types>=0:${PORTSDIR}/devel/p5-Data-Types \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
