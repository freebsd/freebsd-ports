PORTNAME=	abc
DISTVERSION=	g20241117
CATEGORIES=	cad

MAINTAINER=	uddka@student.kit.edu
COMMENT=	System for sequential synthesis and verification
WWW=		https://people.eecs.berkeley.edu/~alanmi/abc/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/copyright.txt

BUILD_DEPENDS=	gmake:devel/gmake

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	berkeley-abc
GH_TAGNAME=	1f3cf0a
USE_LDCONFIG=	yes

CMAKE_ON=	ABC_SKIP_TESTS

BINARY_ALIAS=	make=${GMAKE}

PLIST_FILES=	bin/${PORTNAME} lib/lib${PORTNAME}.so

OPTIONS_DEFINE=			READLINE THREADS
OPTIONS_DEFAULT=		READLINE THREADS

READLINE_USES=			readline
READLINE_CONFIGURE_ENV=		ABC_READLINE_LIBRARIES="-L${LOCALBASE}/lib -lreadline"
READLINE_CONFIGURE_ENV_OFF=	ABC_USE_NO_READLINE=1

THREADS_CONFIGURE_ENV_OFF=	ABC_USE_NO_PTHREADS=1

do-install: # https://github.com/berkeley-abc/abc/issues/71
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
