# $FreeBSD$

PORTNAME=	Data-Util
PORTVERSION=	0.63
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for utilities for data and data types

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-MRO-Compat>=0.09:devel/p5-MRO-Compat \
	p5-Hash-Util-FieldHash-Compat>0:devel/p5-Hash-Util-FieldHash-Compat
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
	p5-Scope-Guard>=0.20:devel/p5-Scope-Guard

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Data/Util/Util.so

.include <bsd.port.mk>
