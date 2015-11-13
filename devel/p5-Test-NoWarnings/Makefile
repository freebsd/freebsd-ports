# Created by: Alex Kapranoff <alex@kapranoff.ru>
# $FreeBSD$

PORTNAME=	Test-NoWarnings
PORTVERSION=	1.04
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Hide and store warnings while running test scripts

LICENSE=	LGPL21

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DEVEL_STACKTRACE
DEVEL_STACKTRACE_DESC=	Stack trace support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEVEL_STACKTRACE}
BUILD_DEPENDS+=	p5-Devel-StackTrace>=0:${PORTSDIR}/devel/p5-Devel-StackTrace
RUN_DEPENDS+=	p5-Devel-StackTrace>=0:${PORTSDIR}/devel/p5-Devel-StackTrace
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001.014:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
