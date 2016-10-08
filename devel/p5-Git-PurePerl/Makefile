# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Git-PurePerl
PORTVERSION=	0.53
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/Git CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pure Perl interface to Git repositories

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Archive-Extract>=0:archivers/p5-Archive-Extract \
		p5-Config-GitLike>=0:devel/p5-Config-GitLike \
		p5-Data-Stream-Bulk>=0:devel/p5-Data-Stream-Bulk \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-File-Find-Rule>0:devel/p5-File-Find-Rule \
		p5-IO-Digest>0:devel/p5-IO-Digest \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-StrictConstructor>=0:devel/p5-MooseX-StrictConstructor \
		p5-MooseX-Types-Path-Class>=0:devel/p5-MooseX-Types-Path-Class \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-utf8>=0:devel/p5-Test-utf8

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
