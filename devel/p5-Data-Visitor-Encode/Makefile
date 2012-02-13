# New ports collection makefile for:	Data::Visitor::Encode
# Date created:		23 Jan 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Data-Visitor-Encode
PORTVERSION=	0.10007
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to encode/decode values in a structure

RUN_DEPENDS=	\
	p5-Data-Visitor>=0.18:${PORTSDIR}/devel/p5-Data-Visitor
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=		Data::Visitor::Encode.3

.include <bsd.port.mk>
