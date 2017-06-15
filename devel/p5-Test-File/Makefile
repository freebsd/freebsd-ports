# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-File
PORTVERSION=	1.44.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test file attributes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-utf8>=0:devel/p5-Test-utf8

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502104
BUILD_DEPENDS+=	p5-Test-Simple>=1.001006:devel/p5-Test-Simple
RUN_DEPENDS+=	p5-Test-Simple>=1.001006:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
