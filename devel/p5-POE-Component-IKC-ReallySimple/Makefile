# New ports collection makefile for:	POE-Component-IKC-ReallySimple
# Date created:		7 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-IKC-ReallySimple
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru
COMMENT=	POE Component for simple inter-kernel communication

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/POE/Component/IKC/Responder.pm:${PORTSDIR}/devel/p5-POE-Component-IKC
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::IKC::ReallySimple.3

.include <bsd.port.mk>
