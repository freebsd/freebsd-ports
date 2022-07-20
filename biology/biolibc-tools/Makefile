PORTNAME=	biolibc-tools
DISTVERSION=	0.1.3
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	High-performance bioinformatics tools based on biolibc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	uthash>0:devel/uthash
LIB_DEPENDS=	libbiolibc.so:biology/biolibc \
		libxtend.so:devel/libxtend \
		libxxhash.so:devel/xxhash

USE_GITHUB=	yes

GH_ACCOUNT=	auerlab

MAKE_ENV=	VERSION=${PORTVERSION}
INSTALL_TARGET=	install-strip

pre-build:
	(cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend)

.include <bsd.port.mk>
