PORTNAME=	EV
DISTVERSION=	4.34
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MLEHMANN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vovkasm@gmail.com
COMMENT=	Perl interface to libev, a high performance full-featured event loop
WWW=		https://metacpan.org/release/EV

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Canary-Stability>=0:devel/p5-Canary-Stability \
		p5-common-sense>=0:devel/p5-common-sense
RUN_DEPENDS=	p5-common-sense>=0:devel/p5-common-sense

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	PERL_MM_USE_DEFAULT="YES"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/EV/EV.so

.include <bsd.port.mk>
