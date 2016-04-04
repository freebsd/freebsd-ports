# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Term-ProgressBar-Quiet
PORTVERSION=	0.31
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to display a progress bar, if interactive

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Term-ProgressBar>=0:devel/p5-Term-ProgressBar \
		p5-Test-MockObject>0:devel/p5-Test-MockObject \
		p5-IO-Interactive>=0:devel/p5-IO-Interactive
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
