PORTNAME=	Syntax-Keyword-Defer
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Execute code when leaving a block
WWW=		https://metacpan.org/pod/Syntax::Keyword::Defer

LICENSE=	ART10

USES=		perl5
USE_PERL5=	modbuild

MY_DEPENDS=	p5-XS-Parse-Keyword>0:devel/p5-XS-Parse-Keyword
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Syntax/Keyword/Defer/Defer.so

.include <bsd.port.mk>
