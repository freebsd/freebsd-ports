# Created by: Geistteufel <geistteufel@yahoo.fr>
# $FreeBSD$

PORTNAME=	Dancer-Debug
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FRANCKC
PKGNAMEPREFIX=	p5-

MAINTAINER=	geistteufel@yahoo.fr
COMMENT=	Dancer::Debug - Extend Plack::Middleware::Debug

RUN_DEPENDS=	p5-Class-Method-Modifiers>=0:${PORTSDIR}/devel/p5-Class-Method-Modifiers \
		p5-Dancer>=0:${PORTSDIR}/www/p5-Dancer \
		p5-Plack-Middleware-Debug>=0:${PORTSDIR}/www/p5-Plack-Middleware-Debug

USES=		perl5
USE_PERL5=	configure

MAN3=		Dancer::Debug.3 \
		Plack::Middleware::Debug::Dancer::Logger.3 \
		Plack::Middleware::Debug::Dancer::Routes.3 \
		Plack::Middleware::Debug::Dancer::Session.3 \
		Plack::Middleware::Debug::Dancer::Settings.3 \
		Plack::Middleware::Debug::Dancer::Version.3

.include <bsd.port.mk>
