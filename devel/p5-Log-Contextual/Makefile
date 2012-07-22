# New ports collection makefile for:	Log::Contextual
# Date created:		10 Dec 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Log-Contextual
PORTVERSION=	0.004201
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple logging interface with a contextual log

RUN_DEPENDS=	\
	p5-Data-Dumper-Concise>0:${PORTSDIR}/devel/p5-Data-Dumper-Concise \
	p5-Exporter-Declare>=0.105:${PORTSDIR}/devel/p5-Exporter-Declare
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Log-Log4perl>0:${PORTSDIR}/devel/p5-Log-Log4perl

PERL_CONFIGURE=	yes

MAN3=	Log::Contextual.3 \
	Log::Contextual::SimpleLogger.3 \
	Log::Contextual::TeeLogger.3 \
	Log::Contextual::WarnLogger.3

.include <bsd.port.mk>
