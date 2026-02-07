PORTNAME=	Object-Pad
PORTVERSION=	0.82.1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	Object-Pad-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple syntax for lexical slot-based objects
WWW=		https://metacpan.org/dist/Object-Pad

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XS-Parse-Keyword>=0.48:devel/p5-XS-Parse-Keyword \
		p5-XS-Parse-Sublike>=0.35:devel/p5-XS-Parse-Sublike
TEST_DEPENDS=	p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Object/Pad/Pad.so

.include <bsd.port.mk>
