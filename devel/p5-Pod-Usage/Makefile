PORTNAME=	Pod-Usage
PORTVERSION=	2.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Print a usage message from embedded pod documentation

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-podlators>=4:textproc/p5-podlators

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-patch:
# Do not conflict with lang/perl5.*
	@${RM} ${WRKSRC}/scripts/pod2usage.PL ${WRKSRC}/t/pod/pod2usage.t

.include <bsd.port.mk>
