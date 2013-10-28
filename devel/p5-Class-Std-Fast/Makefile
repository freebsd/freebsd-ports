# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Class-Std-Fast
PORTVERSION=	0.0.8
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Faster but less secure than Class::Std

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Std>=0.0.9:${PORTSDIR}/devel/p5-Class-Std
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
