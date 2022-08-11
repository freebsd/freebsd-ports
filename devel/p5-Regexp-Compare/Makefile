PORTNAME=	Regexp-Compare
PORTVERSION=	0.33
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Partial ordering for regular expressions

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Regexp/Compare/Compare.so

.include <bsd.port.pre.mk>

# When support for 5.36 is added, keep the check and update to 5.37, as it
# never supports the development branch
.if ${PERL_LEVEL} >= 503600
BROKEN=		does not support 5.36+
.endif

.include <bsd.port.post.mk>
