# New ports collection makefile for:	p5-PerlIO-via-Unidecode
# Date created:		12 Mar 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PerlIO-via-Unidecode
PORTVERSION=	1.01
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A perlio layer for Unidecode

BUILD_DEPENDS=	${SITE_PERL}/Text/Unidecode.pm:${PORTSDIR}/converters/p5-Text-Unidecode
RUN_DEPENDS=	${SITE_PERL}/Text/Unidecode.pm:${PORTSDIR}/converters/p5-Text-Unidecode

PERL_CONFIGURE=	yes

MAN3=		PerlIO::via::Unidecode.3

.include <bsd.port.mk>
