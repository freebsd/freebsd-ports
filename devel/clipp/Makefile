PORTNAME=	clipp
PORTVERSION=	1.2.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command line interfaces for modern C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	include/clipp.h

GH_ACCOUNT=	muellan
USE_GITHUB=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/clipp.h ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>
