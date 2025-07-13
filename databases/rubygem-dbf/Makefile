PORTNAME=	dbf
PORTVERSION=	5.1.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for reading dBase, xBase, Clipper and FoxPro database files
WWW=		https://github.com/infused/dbf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem

RUN_DEPENDS=	rubygem-csv>=0:devel/rubygem-csv

NO_ARCH=	yes

PLIST_FILES=	bin/dbf

CONFLICTS_INSTALL=	dbf # bin/dbf

.include <bsd.port.mk>
