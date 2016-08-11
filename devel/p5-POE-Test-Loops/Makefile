# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	POE-Test-Loops
PORTVERSION=	1.360
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RCAPUTO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reusable tests for POE Loop authors

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-Test-Simple>=1.001002:devel/p5-Test-Simple
RUN_DEPENDS+=	p5-Test-Simple>=1.001002:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
