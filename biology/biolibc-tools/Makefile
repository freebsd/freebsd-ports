# Created by: J. Bacon <jwb@FreeBSD.org>

PORTNAME=	biolibc-tools
DISTVERSION=	0.1.1
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	High-performance bioinformatics tools based on biolibc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	uthash>0:devel/uthash
LIB_DEPENDS=	libbiolibc.so:biology/biolibc \
		libxxhash.so:devel/xxhash

USE_GITHUB=	yes

GH_ACCOUNT=	auerlab

MAKE_ENV=	VERSION=${PORTVERSION}
INSTALL_TARGET=	install-strip

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
