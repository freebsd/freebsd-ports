PORTNAME=	snaky_hash
PORTVERSION=	2.0.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Hashie::Mash joint to make \#snakelife better
WWW=		https://gitlab.com/oauth-xx/snaky_hash

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-hashie-gitlab>=0.1.0<6:devel/rubygem-hashie-gitlab \
		rubygem-version_gem>=1.1.8<3:devel/rubygem-version_gem

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
