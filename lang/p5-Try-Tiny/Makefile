# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Try-Tiny
PORTVERSION=	0.24
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Minimal try/catch with proper localization of $$@

LICENSE=	MIT

TEST_DEPENDS=	p5-Capture-Tiny>=0.12:devel/p5-Capture-Tiny

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502104
TEST_DEPENDS+=	p5-Scalar-List-Utils>=0:lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
