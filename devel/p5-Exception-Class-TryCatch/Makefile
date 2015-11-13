# Created by: Felippe de Meirelles Motta <lippemail@gmail.com>
# $FreeBSD$

PORTNAME=	Exception-Class-TryCatch
PORTVERSION=	1.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Syntactic try/catch sugar for use with Exception::Class

LICENSE=	APACHE20

BUILD_DEPENDS+=	p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class
RUN_DEPENDS+=	p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
