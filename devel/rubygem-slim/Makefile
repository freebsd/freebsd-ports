PORTNAME=	slim
PORTVERSION=	5.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Template language whose goal is reduce the syntax to essential parts
WWW=		https://github.com/slim-template/slim

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-temple>=0.10.0<0.11:devel/rubygem-temple \
		rubygem-tilt>=2.1.0:devel/rubygem-tilt

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/slimrb

.include <bsd.port.mk>
