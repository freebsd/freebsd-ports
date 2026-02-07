PORTNAME=	Sort-Key
PORTVERSION=	1.33
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sorts objects by one or several keys really fast
WWW=		https://metacpan.org/release/Sort-Key

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Sort/Key/Key.so

.include <bsd.port.mk>
