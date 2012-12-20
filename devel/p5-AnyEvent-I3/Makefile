# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	AnyEvent-I3
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Communicate with the i3 window manager

BUILD_DEPENDS=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS
RUN_DEPENDS=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS

PERL_CONFIGURE=	yes

MAN3=		AnyEvent::I3.3

.include <bsd.port.mk>
