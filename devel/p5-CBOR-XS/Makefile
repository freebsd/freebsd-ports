# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	CBOR-XS
PORTVERSION=	1.30
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MLEHMANN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Perl does Concise Binary Object Representation (CBOR, RFC7049)

LICENSE=	GPLv3

USES=		perl5
USE_PERL5=	configure

BUILD_DEPENDS=	p5-Types-Serialiser>=0:devel/p5-Types-Serialiser \
		p5-common-sense>=0:devel/p5-common-sense
RUN_DEPENDS:=	${BUILD_DEPENDS}

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/CBOR/XS/XS.so

.include <bsd.port.mk>
