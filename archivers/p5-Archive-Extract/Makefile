# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Archive-Extract
PORTVERSION=	0.80
PORTREVISION=	1
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generic archive extracting mechanism

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502504
BUILD_DEPENDS+=	p5-Module-Load-Conditional>=0.66:devel/p5-Module-Load-Conditional
RUN_DEPENDS+=	p5-Module-Load-Conditional>=0.66:devel/p5-Module-Load-Conditional
.endif

.include <bsd.port.post.mk>
