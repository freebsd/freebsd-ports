PORTNAME=	launchy
PORTVERSION=	3.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Helper class for launching cross-platform applications
WWW=		https://github.com/copiousfreetime/launchy

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-addressable>=2.8<3:www/rubygem-addressable \
		rubygem-childprocess>=5.0<6:devel/rubygem-childprocess

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/launchy

.include <bsd.port.mk>
