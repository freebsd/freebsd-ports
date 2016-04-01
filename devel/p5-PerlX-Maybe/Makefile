# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PerlX-Maybe
PORTVERSION=	1.001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOBYINK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Return a pair only if they are both defined

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	XS

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

XS_BUILD_DEPENDS=	p5-PerlX-Maybe-XS>=0:devel/p5-PerlX-Maybe-XS
XS_RUN_DEPENDS=		p5-PerlX-Maybe-XS>=0:devel/p5-PerlX-Maybe-XS

.include <bsd.port.mk>
