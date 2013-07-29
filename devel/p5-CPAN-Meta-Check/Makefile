# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CPAN-Meta-Check
PORTVERSION=	0.006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Verify requirements in a CPAN::Meta object

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CPAN-Meta>=2.120920:${PORTSDIR}/devel/p5-CPAN-Meta \
		p5-CPAN-Meta-Requirements>=2.12:${PORTSDIR}/devel/p5-CPAN-Meta-Requirements
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>0:${PORTSDIR}/devel/p5-Test-Deep

PERL_CONFIGURE=	yes

MAN3=		CPAN::Meta::Check.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-Module-Metadata>0:${PORTSDIR}/devel/p5-Module-Metadata
RUN_DEPENDS+=	p5-Module-Metadata>0:${PORTSDIR}/devel/p5-Module-Metadata
.endif

.include <bsd.port.post.mk>
