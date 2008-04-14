# New ports collection makefile for:	p5-Class-Component
# Date created:	Fri Apr 11 16:34:55 2008
# Whom:		Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Component
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cherry@trombik.org
COMMENT=	Pluggable component framework

RUN_DEPENDS=	p5-Carp-Clan>0:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-Inspector>0:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require

PERL_CONFIGURE=	Yes

MAN3=	Class::Component::Component::Plaggerize.3 \
	Class::Component.3 \
	Class::Component::Plugin.3

.include <bsd.port.mk>
