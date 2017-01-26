# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Hash-Merge-Simple
PORTVERSION=	0.051
PORTREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Recursively merge two or more hashes, simply

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Clone>=0:devel/p5-Clone
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Most>=0:devel/p5-Test-Most

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
