PORTNAME=	thor
PORTVERSION=	1.3.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	13

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Scripting framework that replaces rake, sake, and rubigen
WWW=		https://github.com/rails/thor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.3\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/thor

.include <bsd.port.mk>
