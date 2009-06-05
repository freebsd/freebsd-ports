# New ports collection makefile for:	POE-Component-IKC
# Date created:		7 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-IKC
PORTVERSION=	0.2200
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	POE Inter-Kernel Communication

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/POE/API/Peek.pm:${PORTSDIR}/devel/p5-POE-API-Peek \
		${SITE_PERL}/POE/Component/Daemon.pm:${PORTSDIR}/devel/p5-POE-Component-Daemon \
		${SITE_PERL}/${PERL_ARCH}/Proc/ProcessTable.pm:${PORTSDIR}/devel/p5-Proc-ProcessTable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::IKC.3 POE::Component::IKC::Channel.3 \
		POE::Component::IKC::Client.3 POE::Component::IKC::ClientLite.3 \
		POE::Component::IKC::Freezer.3 POE::Component::IKC::Proxy.3 \
		POE::Component::IKC::Responder.3 POE::Component::IKC::Server.3 \
		POE::Component::IKC::Specifier.3

.include <bsd.port.mk>
