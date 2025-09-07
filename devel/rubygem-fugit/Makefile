PORTNAME=	fugit
PORTVERSION=	1.11.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Time tools for flor and the floraison project
WWW=		https://github.com/floraison/fugit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-et-orbi>=1.2.11<2:devel/rubygem-et-orbi \
		rubygem-raabro>=1.4<2:textproc/rubygem-raabro

USES=		gem

NO_ARCH=	yes

# Disable rdoc
OPTIONS_EXCLUDE=DOCS

.include <bsd.port.mk>
