# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XS-Object-Magic
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Opaque, extensible XS pointer backed objects using sv_magic

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0.302:devel/p5-ExtUtils-Depends
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/XS/Object/Magic/Magic.so

.include <bsd.port.mk>
