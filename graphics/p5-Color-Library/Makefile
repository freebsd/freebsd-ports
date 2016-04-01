# Created by: chinsan
# $FreeBSD$

PORTNAME=	Color-Library
PORTVERSION=	0.02.1
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ROKR
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy-to-use and comprehensive named-color library

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Most>=0:devel/p5-Test-Most

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
