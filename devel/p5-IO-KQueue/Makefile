PORTNAME=	IO-KQueue
PORTVERSION=	0.39
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the BSD kqueue system call
WWW=		https://metacpan.org/release/IO-KQueue

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Devel-CheckLib>=0:devel/p5-Devel-CheckLib

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/IO/KQueue/KQueue.so

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
