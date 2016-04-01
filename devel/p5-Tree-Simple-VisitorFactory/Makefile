# Created by: Aaron Dalton <aaron@daltons.ca>
# $FreeBSD$

PORTNAME=	Tree-Simple-VisitorFactory
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Set of visitor objects for traversing Tree::Simple hierarchies

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Tree-Simple>=1.22:devel/p5-Tree-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0.15:devel/p5-Test-Exception

USES=		perl5 tar:tgz
USE_PERL5=	configure

.include <bsd.port.mk>
