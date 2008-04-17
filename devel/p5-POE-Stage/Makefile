# New ports collection makefile for:	POE-Stage
# Date created:	   09 July 2006
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Stage
PORTVERSION=	0.0300
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.03

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Base class for formalized POE components

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/${PERL_ARCH}/PadWalker.pm:${PORTSDIR}/devel/p5-PadWalker \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/${PERL_ARCH}/Devel/LexAlias.pm:${PORTSDIR}/devel/p5-Devel-LexAlias \
		${SITE_PERL}/Lexical/Persistence.pm:${PORTSDIR}/devel/p5-Lexical-Persistence \
		${SITE_PERL}/Attribute/Handlers.pm:${PORTSDIR}/devel/p5-Attribute-Handlers
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Callback.3 POE::Request.3 POE::Request::Emit.3 \
		POE::Request::Recall.3 POE::Request::Return.3 \
		POE::Request::Upward.3 POE::Stage.3 POE::Stage::Echoer.3 \
		POE::Stage::Receiver.3 POE::Stage::Resolver.3 \
		POE::Stage::Ticker.3 POE::Stage::TiedAttributes.3 \
		POE::Watcher.3 POE::Watcher::Delay.3 POE::Watcher::Input.3

.include <bsd.port.mk>
