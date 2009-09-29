# New ports collection makefile for:	devel/p5-Test-Script
# Date created:				Wed Mar  7 20:14:32 CET 2007
# Whom:					lth@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Test-Script
PORTVERSION=	1.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Test::Script - Cross-platform basic tests for scripts

RUN_DEPENDS=	p5-IPC-Run3>=0.034:${PORTSDIR}/devel/p5-IPC-Run3 \
		p5-Probe-Perl>=0.01:${PORTSDIR}/sysutils/p5-Probe-Perl
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Script.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500808
BUILD_DEPENDS+=	p5-Test-Simple>=0.62:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
