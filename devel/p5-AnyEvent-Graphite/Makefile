# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AnyEvent-Graphite
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Non-blocking Graphite client

RUN_DEPENDS=	p5-AnyEvent>=4.15:devel/p5-AnyEvent \
		p5-AnyEvent-SNMP>=1.0:net-mgmt/p5-AnyEvent-SNMP
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
