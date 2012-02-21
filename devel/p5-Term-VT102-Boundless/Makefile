# New ports collection makefile for:	p5-Term-VT102-Boundless
# Date created:		2012-02-21
# Whom:			Andrey Chernov <ache@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Term-VT102-Boundless
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Term
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A subclass to emulate boundless DEC VT102 terminal

BUILD_DEPENDS=	p5-Term-VT102>=0:${PORTSDIR}/devel/p5-Term-VT102
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok

PERL_CONFIGURE=	yes

MAN3=		Term::VT102::Boundless.3

.include <bsd.port.mk>
