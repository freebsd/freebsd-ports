# New ports collection makefile for:	POE-Component-Pluggable
# Date created:	   2006/12/22
# Whom:		   chinsan
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Pluggable
PORTVERSION=	1.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A base class for creating plugin enabled POE Components

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Pluggable.3 POE::Component::Pluggable::Pipeline.3 \
		POE::Component::Pluggable::Constants.3

.include <bsd.port.mk>
