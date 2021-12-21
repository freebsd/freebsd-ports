# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	Object-Pad
PORTVERSION=	0.58
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple syntax for lexical slot-based objects

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-XS-Parse-Keyword>=0.19:devel/p5-XS-Parse-Keyword \
		p5-XS-Parse-Sublike>=0.13:devel/p5-XS-Parse-Sublike
TEST_DEPENDS=	p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Refcount>=0:devel/p5-Test-Refcount

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Object/Pad/Pad.so

.include <bsd.port.mk>
