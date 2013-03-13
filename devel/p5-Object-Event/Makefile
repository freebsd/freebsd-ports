# Created by: Mons Anderson <mons@cpan.org>
# $FreeBSD$

PORTNAME=	Object-Event
PORTVERSION=	1.220
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	mons@cpan.org
COMMENT=	A class that provides an event callback interface

RUN_DEPENDS=	p5-AnyEvent>=3.5:${PORTSDIR}/devel/p5-AnyEvent \
		p5-common-sense>=0:${PORTSDIR}/devel/p5-common-sense

PERL_CONFIGURE=	yes

MAN3=		Object::Event.3

.include <bsd.port.mk>
