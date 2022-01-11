PORTNAME=	IO-FDPass
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to pass a file descriptor over a socket

BUILD_DEPENDS=	p5-Canary-Stability>0:devel/p5-Canary-Stability

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/IO/FDPass/FDPass.so

.include <bsd.port.mk>
