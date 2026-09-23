PORTNAME=	POE-API-Hooks
DISTVERSION=	1.0800
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SUNGO
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S|00$||}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Implement lightweight hooks into POE
WWW=		https://metacpan.org/release/SUNGO/POE-API-Hooks-1.08

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_RUN_DEPENDS=	p5-POE>=0:devel/p5-POE \
		p5-Params-Validate>=0:devel/p5-Params-Validate

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
