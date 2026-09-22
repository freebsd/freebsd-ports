PORTNAME=	Clone-More
DISTVERSION=	0.90.2
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:WAZZUTEKE
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl module for natively copying Perl data structures
WWW=		https://metacpan.org/release/WAZZUTEKE/Clone-More-0.90.2

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

WRKSRC=		${WRKDIR}/Clone-More

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Clone/More/More.so

.include <bsd.port.mk>
