# New ports collection makefile for:	String::Multibyte
# Date created:				25 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	String-Multibyte
PORTVERSION=	1.00
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	String
PKGNAMEPREFIX=	p5-

MAINTAINER=	svenasse@polaris.ca

PERL_CONFIGURE=	yes

MAN3=		String::Multibyte.3 \
		String::Multibyte::Bytes.3 \
		String::Multibyte::EUC.3 \
		String::Multibyte::EUC_JP.3 \
		String::Multibyte::ShiftJIS.3 \
		String::Multibyte::UTF16BE.3 \
		String::Multibyte::UTF16LE.3 \
		String::Multibyte::UTF8.3 \
		String::Multibyte::Unicode.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
