PORTNAME=	Mojo-Base-XS
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES= 	CPAN
MASTER_SITE_SUBDIR= 	CPAN:YKO

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Very fast Mojo-style accessors

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Mojolicious>0:www/p5-Mojolicious

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Mojo/Base/XS/XS.so

.include <bsd.port.mk>
