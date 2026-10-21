PORTNAME=	dry-configurable
PORTVERSION=	1.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Mixin to add configuration functionality to your classes
WWW=		https://github.com/dry-rb/dry-configurable

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-dry-core-gitlab>=1.0<2:devel/rubygem-dry-core-gitlab \
		rubygem-zeitwerk-gitlab>=2.6<3:devel/rubygem-zeitwerk-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
