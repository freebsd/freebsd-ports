# Created by: lth@FreeBSD.org
# $FreeBSD$

PORTNAME=	Test-Script
PORTVERSION=	1.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Test::Script - Cross-platform basic tests for scripts

RUN_DEPENDS=	p5-IPC-Run3>=0.034:devel/p5-IPC-Run3 \
		p5-Probe-Perl>=0.01:sysutils/p5-Probe-Perl
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
