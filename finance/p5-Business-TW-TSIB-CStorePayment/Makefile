# New ports collection makefile for:    p5-Business-TW-TSIB-CStorePayment
# Date created:				2007/10/04
# Whom:	      				chinsan
#
# $FreeBSD$
#

PORTNAME=	Business-TW-TSIB-CStorePayment
PORTVERSION=	0.04
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module for Taishin Bank Convenient Store Payment Management

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Business::TW::TSIB::CStorePayment.3

.include <bsd.port.mk>
