# New ports collection makefile for:	p5-Unicode-Lite
# Date created:				23th March 2003
# Whom:					Maxim Maximov (mcsi@agava.com)
#
# $FreeBSD$
#

PORTNAME=	Unicode-Lite
PORTVERSION=	0.12
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Unicode
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for easy conversion between encodings

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Unicode/String.pm:${PORTSDIR}/converters/p5-Unicode-String \
		${SITE_PERL}/${PERL_ARCH}/Unicode/Map.pm:${PORTSDIR}/converters/p5-Unicode-Map \
		${SITE_PERL}/enum.pm:${PORTSDIR}/devel/p5-enum
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Unicode::Lite.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
