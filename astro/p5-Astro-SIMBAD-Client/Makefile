# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Astro-SIMBAD-Client
PORTVERSION=	0.041
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	OO interface to SIMBAD4

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-SOAP-Lite>=0:net/p5-SOAP-Lite \
		p5-URI>=0:net/p5-URI \
		p5-XML-DoubleEncodedEntities>=1:textproc/p5-XML-DoubleEncodedEntities \
		p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	p5-YAML>=0:textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure

CONFIGURE_ARGS=	-y
NO_ARCH=	yes

.include <bsd.port.mk>
