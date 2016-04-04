# Created by: Takuya Tsuchida <tsucchi@cpan.org>
# $FreeBSD$

PORTNAME=	Test-Module-Used
PORTVERSION=	0.2.3
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TSUCCHI
PKGNAMEPREFIX=	p5-

MAINTAINER=	tsucchi@cpan.org
COMMENT=	Test required module is really used and vice versa

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-CPAN-Meta>=2.102400:devel/p5-CPAN-Meta \
		p5-List-MoreUtils>=0.24:lang/p5-List-MoreUtils \
		p5-Module-CoreList>=2.18:devel/p5-Module-CoreList \
		p5-Module-Used>=v1.2.0:devel/p5-Module-Used \
		p5-PPI>=1.205:textproc/p5-PPI
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
