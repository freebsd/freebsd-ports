# New ports collection makefile for:	p5-Convert-PEM
# Date created:				Tue Sep 11 10:33:05 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>

#
# $FreeBSD$
#

PORTNAME=	Convert-PEM
PORTVERSION=	0.06
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Convert
PKGNAMEPREFIX=	p5-

MAINTAINER=	mharo@FreeBSD.org
COMMENT=	Read/write access to ASN.1-encoded PEM files with optional encryption

PERLBASE=	${SITE_PERL}
BUILD_DEPENDS=	${PERLBASE}/Convert/ASN1.pm:${PORTSDIR}/converters/p5-Convert-ASN1 \
		${PERLBASE}/${PERL_ARCH}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES \
		${PERLBASE}/Crypt/DES_EDE3.pm:${PORTSDIR}/security/p5-Crypt-DES_EDE3 \
		${PERLBASE}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${PERLBASE}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

PERL_CONFIGURE=	YES

MAN3=		Convert::PEM.3 Convert::PEM::CBC.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
