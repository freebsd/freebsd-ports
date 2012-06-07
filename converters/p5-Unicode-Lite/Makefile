# New ports collection makefile for:	p5-Unicode-Lite
# Date created:				23th March 2003
# Whom:					Maxim Maximov (mcsi@agava.com)
#
# $FreeBSD$
#

PORTNAME=	Unicode-Lite
PORTVERSION=	0.12
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for easy conversion between encodings

BUILD_DEPENDS=	p5-Unicode-String>=0:${PORTSDIR}/converters/p5-Unicode-String \
		p5-Unicode-Map>=0:${PORTSDIR}/converters/p5-Unicode-Map \
		p5-enum>=0:${PORTSDIR}/devel/p5-enum
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Unicode::Lite.3

.include <bsd.port.mk>
