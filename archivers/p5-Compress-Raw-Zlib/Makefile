# Created by: Thomas Abthorpe <thomas@goodking.ca>
# $FreeBSD$

PORTNAME=	Compress-Raw-Zlib
PORTVERSION=	2.071
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Low-Level Interface to zlib compression library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Pod>=1:devel/p5-Test-Pod

USE_PERL5=	configure
USES=		perl5

post-patch:
	@${REINPLACE_CMD} -e '/^BUILD_ZLIB/ s|True|False|; /^INCLUDE/ s|= .*$$|= ${INCLUDEDIR}|; /^LIB/ s|= .*$$|= ${LIBDIR}|' ${WRKSRC}/config.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Compress/Raw/Zlib/Zlib.so

.include <bsd.port.mk>
