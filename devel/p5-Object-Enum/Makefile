# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Object-Enum
PORTVERSION=	0.07.3
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Replacement for if ($$foo eq 'bar')

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Sub-Install>=0:devel/p5-Sub-Install \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
