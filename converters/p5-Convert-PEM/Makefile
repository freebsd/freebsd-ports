# New ports collection makefile for:	p5-Convert-PEM
# Date created:				Tue Sep 11 10:33:05 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>

#
# $FreeBSD$
#

PORTNAME=	Convert-PEM
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read/write access to ASN.1-encoded PEM files with optional encryption

BUILD_DEPENDS=	${SITE_PERL}/Convert/ASN1.pm:${PORTSDIR}/converters/p5-Convert-ASN1 \
		${SITE_PERL}/${PERL_ARCH}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES \
		${SITE_PERL}/Crypt/DES_EDE3.pm:${PORTSDIR}/security/p5-Crypt-DES_EDE3 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Class/ErrorHandler.pm:${PORTSDIR}/devel/p5-Class-ErrorHandler
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Convert::PEM.3 Convert::PEM::CBC.3

.include <bsd.port.mk>
