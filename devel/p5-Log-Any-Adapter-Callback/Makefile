# $FreeBSD$

PORTNAME=	Log-Any-Adapter-Callback
PORTVERSION=	0.100
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension adapter for Log::Any with callbacks

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

DEPRECATED=	Use devel/p5-Log-Any (Log::Any::Adapter::Capture) instead
EXPIRATION_DATE=2020-03-31

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Log-Any>0:devel/p5-Log-Any

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
