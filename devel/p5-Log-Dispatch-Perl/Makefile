# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Log-Dispatch-Perl
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Log::Dispatch plug-in using core Perl functions for logging

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Log-Dispatch>=1.16:devel/p5-Log-Dispatch

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
