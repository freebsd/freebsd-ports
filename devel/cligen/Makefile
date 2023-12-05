PORTNAME=	cligen
PORTVERSION=	6.5.0
CATEGORIES=	devel

MAINTAINER=	dave@dogwood.com
COMMENT=	Command-line interface generator
WWW=		https://cligen.se/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		autoreconf bison:alias compiler:c11 gmake

USE_GITHUB=	yes
GH_ACCOUNT=	clicon

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

PLIST_SUB=	LIBMAJORVERSION=${PORTVERSION:R:R} \
		LIBVERSION=${PORTVERSION:R}

.include <bsd.port.mk>
