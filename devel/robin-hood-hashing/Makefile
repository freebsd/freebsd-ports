PORTNAME=	robin-hood-hashing
DISTVERSION=	3.11.5
CATEGORIES=	devel python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast & memory efficient hashtable based on robin hood hashing for C++

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	martinus

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/robin_hood.h

do-install: # see https://github.com/martinus/robin-hood-hashing/issues/162
	${INSTALL_DATA} ${WRKSRC}/src/include/robin_hood.h ${STAGEDIR}${PREFIX}/include

# tests fail to build, see https://github.com/martinus/robin-hood-hashing/issues/161

.include <bsd.port.mk>
