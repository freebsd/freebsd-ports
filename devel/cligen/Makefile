PORTNAME=	cligen
PORTVERSION=	5.8.0
CATEGORIES=	devel

MAINTAINER=	dcornejo@netgate.com
COMMENT=	Command-line interface generator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		bison:alias compiler:c11 gmake

USE_GITHUB=	yes
GH_ACCOUNT=	clicon

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

PLIST_SUB=	LIBMAJORVERSION=${PORTVERSION:R:R} \
		LIBVERSION=${PORTVERSION:R}

.include <bsd.port.mk>
