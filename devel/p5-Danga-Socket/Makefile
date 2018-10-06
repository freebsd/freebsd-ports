# Created by: Jacques Marneweck <jacques@php.net>
# $FreeBSD$

PORTNAME=	Danga-Socket
PORTVERSION=	1.61
PORTREVISION=	1
CATEGORIES=	devel net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Event loop and event-driven async socket base class

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-KQueue>=0:devel/p5-IO-KQueue \
		p5-Sys-Syscall>=0:devel/p5-Sys-Syscall

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
