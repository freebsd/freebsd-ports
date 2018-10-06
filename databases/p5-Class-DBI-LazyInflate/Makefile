# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Class-DBI-LazyInflate
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Defer inflating of columns until they are used

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Lazy>=0:devel/p5-Data-Lazy \
		p5-Class-DBI>=0:databases/p5-Class-DBI

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
