PORTNAME=	Test-Module-Runnable
DISTVERSION=	0.6.2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=CPAN:DDRP
MAINTAINER=	palmer@overchat.org
COMMENT=	Test::Module::Runnable
WWW=		https://metacpan.org/pod/Test::Module::Runnable
USES=		perl5
USE_PERL5=	configure build run
PORTREVISION=	1
LICENSE=	BSD3CLAUSE
NO_ARCH=	yes
PKGNAMEPREFIX=	p5-

MY_DEPENDS=\
	p5-Moose>0:devel/p5-Moose \
	p5-Test-MockModule>0:devel/p5-Test-MockModule

BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

TEST_DEPENDS=\
	${MY_DEPENDS} \
	p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
	p5-Test-Deep>0:devel/p5-Test-Deep \
	p5-Test-Exception>0:devel/p5-Test-Exception \
	p5-Test-Output>0:devel/p5-Test-Output

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 5
TEST_DEPENDS+=	p5-Module-CoreList>0:devel/p5-Module-CoreList
.endif

.include <bsd.port.post.mk>
