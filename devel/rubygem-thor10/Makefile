#
PORTNAME=	thor
PORTVERSION=	1.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	10

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Scripting framework that replaces rake, sake, and rubigen
WWW=		https://github.com/erikhuda/thor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.0\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/thor

.include <bsd.port.mk>
