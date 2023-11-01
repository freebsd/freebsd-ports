PORTNAME=	System2
PORTVERSION=	0.85.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Like system(), but with STDERR available as well
WWW=		https://metacpan.org/release/System2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:R}

pre-configure:
	${RM} ${WRKSRC}/io_test.pl

.include <bsd.port.mk>
