# Created by: Evgeniy Kosov <evgeniy@kosov.su>
# $FreeBSD$

PORTNAME=	Getopt-Compact
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Getopt processing in a compact statement with long and short options

RUN_DEPENDS=	p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-Text-Table>=0:${PORTSDIR}/textproc/p5-Text-Table \
		p5-Env-Path>=0:${PORTSDIR}/devel/p5-Env-Path
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
