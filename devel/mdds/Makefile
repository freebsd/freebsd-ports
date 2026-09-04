PORTNAME=	mdds
PORTVERSION=	3.2.1
CATEGORIES=	devel
#MASTER_SITES=	https://kohei.us/files/mdds/src/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Multi-dimensional data index algorithm
WWW=		https://gitlab.com/mdds/mdds

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake pkgconfig tar:xz
GNU_CONFIGURE=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	mdds

PLIST_SUB=	API_VERSION=${MDDS_API_VERSION}
.include "${.CURDIR}/../../devel/mdds/Makefile.version"

.include <bsd.port.mk>
