# Created by: Aaron Dalton <aaron@daltons.ca>
# $FreeBSD$

PORTNAME=	Tree-Simple-View
PORTVERSION=	0.18.0002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MZIESCHA
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Set of classes for viewing Tree::Simple hierarchies

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Throwable>=0.10:devel/p5-Class-Throwable \
		p5-Tree-Simple>=1.07:devel/p5-Tree-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0.15:devel/p5-Test-Exception \
		p5-Test-LongString>=0:devel/p5-Test-LongString

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
