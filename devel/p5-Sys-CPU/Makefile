PORTNAME=	Sys-CPU
DISTVERSION=	0.61
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MZSANFORD
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for getting CPU information
WWW=		https://metacpan.org/release/MZSANFORD/Sys-CPU-0.61

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		dos2unix perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Sys/CPU/CPU.so

.include <bsd.port.mk>
