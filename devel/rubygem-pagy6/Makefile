PORTNAME=	pagy
PORTVERSION=	6.5.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	6

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Agnostic pagination in plain Ruby
WWW=		https://ddnexus.github.io/pagy/ \
		https://github.com/ddnexus/pagy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/pagy

.include <bsd.port.mk>
