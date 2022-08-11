PORTNAME=	marginalia
PORTVERSION=	1.10.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Attach comments to your ActiveRecord queries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack61>=2.3:www/rubygem-actionpack61 \
		rubygem-activerecord61>=2.3:databases/rubygem-activerecord61

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
