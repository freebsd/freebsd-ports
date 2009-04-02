# New ports collection makefile for:	p5-Bio-Glite
# Date created:				1st April, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Bio-Glite
PORTVERSION=	0.10
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	An Perl Interface to G-language

BUILD_DEPENDS=	p5-Data-Dumper>=2.121:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-libwww>=5:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=	Bio::Glite.3

.include <bsd.port.mk>
