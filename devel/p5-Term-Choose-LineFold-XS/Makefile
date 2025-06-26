PORTNAME=	Term-Choose-LineFold-XS
PORTVERSION=	0.002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS acceleration for Term-Choose-LineFold
WWW=		https://metacpan.org/dist/Term-Choose-LineFold-XS

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Term/Choose/LineFold/XS/XS.so

.include <bsd.port.mk>
