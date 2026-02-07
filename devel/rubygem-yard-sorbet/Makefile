PORTNAME=	yard-sorbet
PORTVERSION=	0.9.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	YARD plugin that incorporates Sorbet type information
WWW=		https://github.com/dduugg/yard-sorbet

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-sorbet-runtime>=0:devel/rubygem-sorbet-runtime \
		rubygem-yard>=0:textproc/rubygem-yard

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
