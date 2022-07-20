PORTNAME=	Inline-CPP
PORTVERSION=	0.80
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Write Perl subroutines and classes in C++

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-ExtUtils-CppGuess>=0.15:devel/p5-ExtUtils-CppGuess \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Inline>=0.82:devel/p5-Inline \
		p5-Inline-C>=0.80:devel/p5-Inline-C \
		p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Inline/CPP/Config.pm.in

.include <bsd.port.mk>
