# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Business-OnlinePayment-iAuthorizer
PORTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	finance perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Business::OnlinePayment backend module for iAuthorizer

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Business-OnlinePayment>=0:finance/p5-Business-OnlinePayment
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		perl5 shebangfix
SHEBANG_FILES=	certification.pl
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
