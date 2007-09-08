# New ports collection makefile for:	p5-Encode-compat
# Date created:				Mon April 14th, 2003
# Whom:					Erwin Lansing <erwin@lansing.dk>
#
# $FreeBSD$
#

PORTNAME=	Encode-compat
PORTVERSION=	0.07
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Encode
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Compatibility interfaces for Encode.pm on Perl < 5.7.1

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Encode::compat.3 Encode::compat::Alias.3

.include <bsd.port.mk>
