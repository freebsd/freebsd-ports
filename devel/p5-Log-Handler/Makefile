# New ports collection makefile for:	Log::Handler
# Date created:				7 Nov 2009
# Whom:					Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	Log-Handler
PORTVERSION=	0.75
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	An object-oriented handler for logging, tracing, and debugging in Perl

BUILD_DEPENDS=	p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Log::Handler.3 \
		Log::Handler::Config.3 \
		Log::Handler::Examples.3 \
		Log::Handler::Levels.3 \
		Log::Handler::Output.3 \
		Log::Handler::Output::DBI.3 \
		Log::Handler::Output::Email.3 \
		Log::Handler::Output::File.3 \
		Log::Handler::Output::Forward.3 \
		Log::Handler::Output::Screen.3 \
		Log::Handler::Output::Sendmail.3 \
		Log::Handler::Output::Socket.3 \
		Log::Handler::Pattern.3 \
		Log::Handler::Plugin::Config::General.3 \
		Log::Handler::Plugin::Config::Properties.3 \
		Log::Handler::Plugin::YAML.3

.include <bsd.port.mk>
