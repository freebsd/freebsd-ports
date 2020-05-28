# Created by: Aaron Dalton <aaron@daltons.ca>
# $FreeBSD$

PORTNAME=	File-Random
PORTVERSION=	0.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl module for random selecting of a file

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Set-Scalar>0:devel/p5-Set-Scalar \
		p5-Want>=0:devel/p5-Want
TEST_DEPENDS=	p5-Test-Class>=0.03:devel/p5-Test-Class \
		p5-Test-Differences>=0.43:devel/p5-Test-Differences \
		p5-Test-Exception>0.1:devel/p5-Test-Exception \
		p5-Test-ManyParams>0:devel/p5-Test-ManyParams \
		p5-Test-Warn>0.05:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
