# New ports collection makefile for:    p5-Business-TW-TSIB-VirtualAccount
# Date created:				2007/10/04
# Whom:	      				chinsan
#
# $FreeBSD$
#

PORTNAME=	Business-TW-TSIB-VirtualAccount
PORTVERSION=	0.04b
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module for Taishin Bank Virtual Account Management

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Business::TW::TSIB::VirtualAccount.3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/b//}

.include <bsd.port.mk>
