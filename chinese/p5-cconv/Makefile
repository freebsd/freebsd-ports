# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cconv
PORTVERSION=	0.6.1
DISTVERSIONPREFIX=	perl-
PORTREVISION=	2
CATEGORIES=	chinese converters perl5
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl wrapper for chinese/cconv

LICENSE=	GPLv2

LIB_DEPENDS=	libcconv.so:${PORTSDIR}/chinese/cconv

USE_PERL5=	configure
USES=		localbase perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/cconv/cconv.so

.include <bsd.port.mk>
