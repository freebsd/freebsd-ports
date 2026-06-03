PORTNAME=	Filter
PORTVERSION=	1.65
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RURBAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Number of source filters for perl5 programs
WWW=		https://metacpan.org/release/Filter

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Filter/Util/Call/Call.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Filter/Util/Exec/Exec.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Filter/decrypt/decrypt.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Filter/tee/tee.so

.include <bsd.port.mk>
