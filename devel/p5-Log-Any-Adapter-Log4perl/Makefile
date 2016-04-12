# Created by: Evgeniy Kosov <evgeniy@kosov.su>
# $FreeBSD$

PORTNAME=	Log-Any-Adapter-Log4perl
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Log::Any adapter for Log4perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Log-Any>=1.03:devel/p5-Log-Any \
		p5-Log-Log4perl>=1.32:devel/p5-Log-Log4perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
