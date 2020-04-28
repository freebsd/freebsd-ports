# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Object
PORTVERSION=	2.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data Type Objects for Perl 5

LICENSE=	APACHE20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Object-Cast>=0.02:devel/p5-Data-Object-Cast \
		p5-Data-Object-Class>=2.02:devel/p5-Data-Object-Class \
		p5-Data-Object-ClassHas>=2.01:devel/p5-Data-Object-ClassHas \
		p5-Data-Object-Kind>=0.01:devel/p5-Data-Object-Kind \
		p5-Data-Object-Role-Buildable>=0.03:devel/p5-Data-Object-Role-Buildable \
		p5-Data-Object-Role-Dumpable>=2.01:devel/p5-Data-Object-Role-Dumpable \
		p5-Data-Object-Role-Proxyable>=2.03:devel/p5-Data-Object-Role-Proxyable \
		p5-Data-Object-Role-Throwable>=2.01:devel/p5-Data-Object-Role-Throwable \
		p5-Data-Object-Types>=0.04:devel/p5-Data-Object-Types

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
