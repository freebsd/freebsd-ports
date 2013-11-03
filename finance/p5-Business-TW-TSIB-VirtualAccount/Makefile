# Created by: chinsan
# $FreeBSD$

PORTNAME=	Business-TW-TSIB-VirtualAccount
PORTVERSION=	0.04b
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module for Taishin Bank Virtual Account Management

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/b//}

.include <bsd.port.mk>
