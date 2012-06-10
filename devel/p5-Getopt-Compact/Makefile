# New ports collection makefile for:	p5-Getopt-Compact
# Date created:				July 16th 2010
# Whom:	      				Evgeniy Kosov <evgeniy@kosov.su>
#
# $FreeBSD$
#

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

PERL_CONFIGURE=	yes

MAN3=		Getopt::Compact.3 \
		Getopt::Compact::PodMunger.3

.include <bsd.port.mk>
