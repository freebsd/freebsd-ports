PORTNAME=	Domain-PublicSuffix
PORTVERSION=	0.21
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NMELNICK
PKGNAMEPREFIX=	p5-

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Parse a domain down to the root TLD
WWW=		https://metacpan.org/release/Domain-PublicSuffix

LICENSE=	ARTPERL10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Class-Accessor-Fast-XS>=0:devel/p5-Class-Accessor-Fast-XS \
		p5-Net-IDN-Encode>=2.401:textproc/p5-Net-IDN-Encode \
		public_suffix_list>0:dns/public_suffix_list

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-patch:
		@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			${WRKSRC}/lib/Domain/PublicSuffix.pm
		@${RM} ${WRKSRC}/lib/Domain/*.orig ${WRKSRC}/lib/Domain/*.bak

.include <bsd.port.mk>
