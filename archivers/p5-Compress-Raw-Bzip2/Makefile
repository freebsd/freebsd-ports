# Created by: Thomas Abthorpe <thomas@goodking.ca>
# $FreeBSD$

PORTNAME=	Compress-Raw-Bzip2
PORTVERSION=	2.070
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Low-Level Interface to bzip2 compression library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Pod>=1:devel/p5-Test-Pod

USE_PERL5=	configure
USES=		perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Compress/Raw/Bzip2/Bzip2.so

.include <bsd.port.mk>
