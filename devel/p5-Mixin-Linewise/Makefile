# $FreeBSD$

PORTNAME=	Mixin-Linewise
PORTVERSION=	0.108
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write your linewise code for handles; this does the rest

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-PerlIO-utf8_strict>=0:devel/p5-PerlIO-utf8_strict \
		p5-Sub-Exporter>=0.900:devel/p5-Sub-Exporter
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
