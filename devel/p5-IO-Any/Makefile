# New ports collection makefile for:	p5-IO-Any
# Date created:		2011-05-26
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Any
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	IO::Any opens anything

BUILD_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp
RUN_DEPENDS=	p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy
TEST_DEPENDS=	p5-Test-Differences>=0:${PORTSDIR}/devel/Test-Differences \
		p5-Test-Exception>=0:${PORTSDIR}/devel/Test-Exception

PERL_CONFIGURE=	yes

MAN3=		IO::Any.3

.include <bsd.port.mk>
