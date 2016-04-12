# Created by: chinsan
# $FreeBSD$

PORTNAME=	Business-TW-TSIB-VirtualAccount
PORTVERSION=	0.04b
PORTREVISION=	2
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module for Taishin Bank Virtual Account Management

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-DateTime>=0:devel/p5-DateTime
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/b//}

PORTSCOUT=	skipv:0.04

.include <bsd.port.mk>
