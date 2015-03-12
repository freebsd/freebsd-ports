# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Class-XSAccessor-Array
PORTVERSION=	1.04
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SMUELLER
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module for unloading classes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-AutoXS-Header>=0:${PORTSDIR}/devel/p5-AutoXS-Header
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-install:
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Class/XSAccessor/Array/Array.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Class/XSAccessor/Array/Array.so
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Class/XSAccessor/Array/Array.so

.include <bsd.port.mk>
