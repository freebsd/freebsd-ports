# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	IO-AIO
PORTVERSION=	4.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Asynchronous Input/Output

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Canary-Stability>=2001:devel/p5-Canary-Stability \
		p5-common-sense>=0:devel/p5-common-sense
RUN_DEPENDS=	p5-common-sense>=0:devel/p5-common-sense

USES=		perl5
USE_PERL5=	configure

pre-build:
	cd ${WRKSRC}/ && ${PERL} gendef0

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/IO/AIO/AIO.so

.include <bsd.port.mk>
