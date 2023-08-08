PORTNAME=	mixlib-install
PORTVERSION=	3.12.27
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to interact with the software distribution system in Chef
WWW=		https://www.chef.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mixlib-shellout>=0:devel/rubygem-mixlib-shellout \
		rubygem-mixlib-versioning>=0:devel/rubygem-mixlib-versioning \
		rubygem-thor>=0:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/mixlib-install

.include <bsd.port.mk>
