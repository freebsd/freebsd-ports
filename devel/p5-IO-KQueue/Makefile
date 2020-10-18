# $FreeBSD$

PORTNAME=	IO-KQueue
PORTVERSION=	0.39
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl interface to the BSD kqueue system call

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	${_BUILD_RUN_DEPENDS}
RUN_DEPENDS=	${_BUILD_RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

_BUILD_RUN_DEPENDS=	p5-Devel-CheckLib>=0:devel/p5-Devel-CheckLib

post-install:
	${STRIP_CMD} ${STAGEDIR}${SITE_ARCH}/auto/IO/KQueue/KQueue.so

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
