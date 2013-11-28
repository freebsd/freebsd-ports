# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cconv
PORTVERSION=	0.6.1
CATEGORIES=	chinese converters perl5
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-perl-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl wrapper for chinese/cconv

LICENSE=	GPLv2

LIB_DEPENDS=	libcconv.so:${PORTSDIR}/chinese/cconv

CFLAGS+=	-I${LOCALBASE}/include
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
