# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Module-Math-Depends
PORTVERSION=	0.02
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Convenience object for manipulating module dependencies

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Params-Util>=0:devel/p5-Params-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
