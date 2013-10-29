# Created by: chinsan
# $FreeBSD$

PORTNAME=	Hash-Util-FieldHash-Compat
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use Hash::Util::FieldHash or ties, depending on availability

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Tie-RefHash>=1.38:${PORTSDIR}/devel/p5-Tie-RefHash \
		p5-Tie-RefHash-Weak>=0.08:${PORTSDIR}/devel/p5-Tie-RefHash-Weak
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
