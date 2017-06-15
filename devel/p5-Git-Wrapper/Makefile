# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Git-Wrapper
PORTVERSION=	0.047
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Wrap git(7) command-line interface

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	git:devel/git \
		p5-File-chdir>=0:devel/p5-File-chdir \
		p5-Devel-CheckBin>=0:devel/p5-Devel-CheckBin \
		p5-Sort-Versions>=0:devel/p5-Sort-Versions
RUN_DEPENDS:=	${BUILD_DEPENDS:Np5-Devel-CheckBin*}
TEST_DEPENDS=	p5-Path-Class>=0.26:devel/p5-Path-Class \
		p5-Sort-Versions>=0:devel/p5-Sort-Versions \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
