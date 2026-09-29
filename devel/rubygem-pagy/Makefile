PORTNAME=	pagy
PORTVERSION=	43.6.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Agnostic pagination in plain Ruby
WWW=		https://ddnexus.github.io/pagy/ \
		https://github.com/ddnexus/pagy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-json>=0:devel/rubygem-json \
		rubygem-psych>=0:textproc/rubygem-psych \
		rubygem-uri>=0:net/rubygem-uri

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/pagy

.include <bsd.port.mk>
