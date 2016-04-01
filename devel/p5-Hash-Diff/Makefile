# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Hash-Diff
PORTVERSION=	0.007
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Return the difference between two hashes as a hash

RUN_DEPENDS=	p5-Hash-Merge>=0.12:textproc/p5-Hash-Merge
BUILD_DEPENDS=	p5-Hash-Merge>=0.12:textproc/p5-Hash-Merge
TEST_DEPENDS=	p5-Test-Simple>=0.98:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001.014:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
