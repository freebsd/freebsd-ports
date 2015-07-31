# Created by: chinsan
# $FreeBSD$

PORTNAME=	Hash-Util-FieldHash-Compat
PORTVERSION=	0.08
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use Hash::Util::FieldHash or ties, depending on availability

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Tie-RefHash-Weak>=0.08:${PORTSDIR}/devel/p5-Tie-RefHash-Weak
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS=	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
