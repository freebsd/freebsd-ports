PORTNAME=	marginalia
PORTVERSION=	1.11.1
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Attach comments to your ActiveRecord queries
WWW=		https://github.com/basecamp/marginalia

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack70>=2.3:www/rubygem-actionpack70 \
		rubygem-activerecord70>=2.3:databases/rubygem-activerecord70

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project

NO_ARCH=	yes

.include <bsd.port.mk>
