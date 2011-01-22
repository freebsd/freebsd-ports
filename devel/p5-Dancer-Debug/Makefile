# New ports collection makefile for:	p5-Dancer-Debug
# Date created:		18 january 2011
# Whom:			Geistteufel <geistteufel@yahoo.fr>
#
# $FreeBSD$
#

PORTNAME=	Dancer-Debug
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/../../authors/id/F/FR/FRANCKC/
PKGNAMEPREFIX=	p5-

MAINTAINER=	geistteufel@yahoo.fr
COMMENT=	Dancer::Debug - Extend Plack::Middleware::Debug

RUN_DEPENDS=	p5-Class-Method-Modifiers>=0:${PORTSDIR}/devel/p5-Class-Method-Modifiers \
		p5-Dancer>=0:${PORTSDIR}/www/p5-Dancer \
		p5-Plack-Middleware-Debug>=0:${PORTSDIR}/www/p5-Plack-Middleware-Debug

PERL_CONFIGURE=	yes

MAN3=		Dancer::Debug.3 \
		Plack::Middleware::Debug::Dancer::Logger.3 \
		Plack::Middleware::Debug::Dancer::Routes.3 \
		Plack::Middleware::Debug::Dancer::Session.3 \
		Plack::Middleware::Debug::Dancer::Settings.3 \
		Plack::Middleware::Debug::Dancer::Version.3

.include <bsd.port.mk>
