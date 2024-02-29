PORTNAME=	Hash-SharedMem
PORTVERSION=	0.005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Efficient shared mutable hash
WWW=		https://metacpan.org/release/Hash-SharedMem

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Devel-CallChecker>0:devel/p5-Devel-CallChecker \
		p5-Scalar-String>0:devel/p5-Scalar-String
RUN_DEPENDS=	p5-Devel-CallChecker>0:devel/p5-Devel-CallChecker \
		p5-Scalar-String>0:devel/p5-Scalar-String

USES=		perl5
USE_PERL5=	modbuild

PLIST_FILES=	${SITE_ARCH_REL}/auto/Hash/SharedMem/SharedMem.so \
		${SITE_ARCH_REL}/Hash/SharedMem.pm \
		${SITE_ARCH_REL}/Hash/SharedMem/Handle.pm \
		${SITE_MAN3_REL}/Hash::SharedMem.3.gz \
		${SITE_MAN3_REL}/Hash::SharedMem::Handle.3.gz

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Hash/SharedMem/SharedMem.so

.include <bsd.port.mk>
