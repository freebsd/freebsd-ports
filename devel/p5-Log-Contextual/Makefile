# $FreeBSD$

PORTNAME=	Log-Contextual
PORTVERSION=	0.005003
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple logging interface with a contextual log

RUN_DEPENDS=	\
	p5-Data-Dumper-Concise>0:${PORTSDIR}/devel/p5-Data-Dumper-Concise \
	p5-Exporter-Declare>=0.106:${PORTSDIR}/devel/p5-Exporter-Declare \
	p5-Moo>0:${PORTSDIR}/devel/p5-Moo
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Log-Log4perl>0:${PORTSDIR}/devel/p5-Log-Log4perl

PERL_CONFIGURE=	yes

MAN3=	Log::Contextual.3 \
	Log::Contextual::Role::Router.3 \
	Log::Contextual::SimpleLogger.3 \
	Log::Contextual::TeeLogger.3 \
	Log::Contextual::WarnLogger.3

.include <bsd.port.mk>
