# New ports collection makefile for:	p5-Convert-PEM
# Date created:				Tue Sep 11 10:33:05 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Convert-PEM
PORTVERSION=	0.07
PORTREVISION=	2
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read/write access to ASN.1-encoded PEM files with optional encryption

RUN_DEPENDS=	p5-Class-ErrorHandler>=0:${PORTSDIR}/devel/p5-Class-ErrorHandler \
		p5-Convert-ASN1>=0.10:${PORTSDIR}/converters/p5-Convert-ASN1 \
		p5-Crypt-DES_EDE3>=0:${PORTSDIR}/security/p5-Crypt-DES_EDE3
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Convert::PEM.3 Convert::PEM::CBC.3

.include <bsd.port.mk>
