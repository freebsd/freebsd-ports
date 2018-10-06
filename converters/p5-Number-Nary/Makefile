# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Number-Nary
PORTVERSION=	1.100312
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Encode and decode numbers as n-ary strings

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-UDCode>=0:devel/p5-UDCode

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
