# Created by: will
# $FreeBSD$

PORTNAME=	Class-Tom
PORTVERSION=	3.02
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A perl module to transport objects from one system to another

BUILD_DEPENDS=	p5-Devel-Symdump>=0:${PORTSDIR}/devel/p5-Devel-Symdump
RUN_DEPENDS=	p5-Devel-Symdump>=0:${PORTSDIR}/devel/p5-Devel-Symdump

USES=		perl5
USE_PERL5=	configure

MAN3=		Class::Tom.3

NO_STAGE=	yes
.include <bsd.port.mk>
