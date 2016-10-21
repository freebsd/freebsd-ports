# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Async
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The Orphanange of Asynchronous Love Children

RUN_DEPENDS=	p5-Moose>=0.56:devel/p5-Moose \
		p5-MooseX-AttributeHelpers>=0.13:devel/p5-MooseX-AttributeHelpers
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-extract:
	@${RM} ${WRKSRC}/lib/MooseX/._Async.pm

.include <bsd.port.mk>
