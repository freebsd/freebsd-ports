# Created by: Mikhail T. <michael@fun-box.ru>
# $FreeBSD$

PORTNAME=	Async-Interrupt
PORTVERSION=	1.26
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Allow C/XS libraries to interrupt perl asynchronously

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Canary-Stability>=0:devel/p5-Canary-Stability \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-common-sense>=0:devel/p5-common-sense

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Async/Interrupt/Interrupt.so

.include <bsd.port.mk>
