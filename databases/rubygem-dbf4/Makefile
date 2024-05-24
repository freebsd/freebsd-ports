PORTNAME=	dbf
PORTVERSION=	4.3.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for reading dBase, xBase, Clipper and FoxPro database files
WWW=		https://github.com/infused/dbf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem

RUN_DEPENDS=	rubygem-csv>=0:devel/rubygem-csv

NO_ARCH=	yes

PORTSCOUT=	limit:^4\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/dbf

.include <bsd.port.mk>
