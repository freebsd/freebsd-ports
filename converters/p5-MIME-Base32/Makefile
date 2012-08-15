# New ports collection makefile for:	p5-MIME-Base32
# Date created:				2005-10-19
# Whom:					nork@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	MIME-Base32
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module for Base32 encodings

PERL_CONFIGURE=	YES

MAN3=		MIME::Base32.3

post-extract:
	@${RM} ${WRKSRC}/test1.pl

.include <bsd.port.mk>
