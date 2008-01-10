# New ports collection makefile for:	p5-Event-Notify
# Date created:		2008-01-03
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	Event-Notify
PORTVERSION=	0.00004
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Event
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Simple Observer/Notifier

BUILD_DEPENDS=	p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject
RUN_DEPENDS=	p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject

PERL_CONFIGURE=	yes

MAN3=		Event::Notify.3

.include <bsd.port.mk>
