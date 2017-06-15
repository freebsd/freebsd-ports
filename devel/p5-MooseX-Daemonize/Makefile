# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Daemonize
PORTVERSION=	0.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Role for daemonizing your Moose based application

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.33:devel/p5-Moose \
		p5-MooseX-Getopt>=0.07:devel/p5-MooseX-Getopt \
		p5-MooseX-Types-Path-Class>=0:devel/p5-MooseX-Types-Path-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Devel-CheckOS>=1.63:devel/p5-Devel-CheckOS

DEPRECATED=	Deprecated by upstream, use devel/p5-Daemon-Control instead
EXPIRATION_DATE=	2017-03-01

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
