PORTNAME=	Algorithm-Cluster
PORTVERSION=	1.59
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MDEHOON
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to C clustering library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if (${ARCH} == powerpc || ${ARCH} == i386) && ${/usr/bin/ld:L:tA} == /usr/bin/ld.lld
USE_GCC=	yes
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Algorithm/Cluster/Cluster.so

.include <bsd.port.mk>
