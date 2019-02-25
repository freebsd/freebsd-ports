# Created by: Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JSON-XS
PORTVERSION=	4.01
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON serialising/deserialising, done correctly and fast

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Types-Serialiser>=0:devel/p5-Types-Serialiser \
		p5-common-sense>0:devel/p5-common-sense

USES=		perl5
USE_PERL5=	configure

post-patch:
# This dependency does nothing and is safe to remove
	@${REINPLACE_CMD} -e '/use Canary::Stability/d' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/JSON/XS/XS.so

.include <bsd.port.mk>
