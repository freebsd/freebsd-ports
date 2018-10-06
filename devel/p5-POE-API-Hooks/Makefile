# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	POE-API-Hooks
PORTVERSION=	1.0800
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S|00$||}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Implement lightweight hooks into POE

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-POE>=0:devel/p5-POE \
		p5-Params-Validate>=0:devel/p5-Params-Validate

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
