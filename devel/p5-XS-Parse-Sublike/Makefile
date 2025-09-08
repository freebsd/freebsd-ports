PORTNAME=	XS-Parse-Sublike
PORTVERSION=	0.38
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS functions to assist in parsing sub-like syntax
WWW=		https://metacpan.org/dist/XS-Parse-Sublike

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	modbuild

PORTSCOUT=	limit:^[0-9\.]*$$

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/XS/Parse/Sublike/Sublike.so

.include <bsd.port.mk>
