# New ports collection makefile for:	p5-JSON-RPC-Common
# Date created:				03 July, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	JSON-RPC-Common
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Transport agnostic JSON RPC helper objects

RUN_DEPENDS=	p5-Moose>=0.81:${PORTSDIR}/devel/p5-Moose \
		p5-JSON>=2.11:${PORTSDIR}/converters/p5-JSON \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok \
		p5-namespace-clean>=0.08:${PORTSDIR}/devel/p5-namespace-clean

PERL_CONFIGURE=	YES

MAN3=		JSON::RPC::Common::Marshal::Text.3 \
		JSON::RPC::Common::Procedure::Call.3 \
		JSON::RPC::Common::Procedure::Return::Version_1_1.3 \
		JSON::RPC::Common::Procedure::Return::Error.3 \
		JSON::RPC::Common::Procedure::Call::Version_1_0.3 \
		JSON::RPC::Common::Procedure::Return.3 \
		JSON::RPC::Common.3 \
		JSON::RPC::Common::Procedure::Return::Version_2_0.3 \
		JSON::RPC::Common::Procedure::Return::Version_1_0.3 \
		JSON::RPC::Common::Procedure::Call::Version_1_1.3 \
		JSON::RPC::Common::Procedure::Return::Version_2_0::Error.3 \
		JSON::RPC::Common::TypeConstraints.3 \
		JSON::RPC::Common::Procedure::Return::Version_1_1::Error.3 \
		JSON::RPC::Common::Procedure::Call::Version_2_0.3 \
		JSON::RPC::Common::Procedure::Return::Version_1_0::Error.3 \
		JSON::RPC::Common::Marshal::HTTP.3

.include <bsd.port.mk>
