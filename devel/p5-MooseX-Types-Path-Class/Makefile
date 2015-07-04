# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Types-Path-Class
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Path::Class type library for Moose

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Getopt>=0:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-MooseX-Types>=0.04:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Path-Class>=0.16:${PORTSDIR}/devel/p5-Path-Class
BUILD_DEPENDS:=	${RUN_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
