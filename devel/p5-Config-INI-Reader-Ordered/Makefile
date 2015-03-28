# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Config-INI-Reader-Ordered
PORTVERSION=	0.011
CATEGORIES=	perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HDP
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	INI-file parser that returns sections in order

BUILD_DEPENDS=	p5-Config-INI>=0:${PORTSDIR}/devel/p5-Config-INI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
