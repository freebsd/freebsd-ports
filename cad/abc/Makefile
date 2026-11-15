PORTNAME=	abc
DISTVERSION=	g20261114
PORTEPOCH=	1
CATEGORIES=	cad

MAINTAINER=	alven@FreeBSD.org
COMMENT=	System for sequential synthesis and verification
WWW=		https://people.eecs.berkeley.edu/~alanmi/abc/ \
		https://github.com/berkeley-abc/abc/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/copyright.txt

NOT_FOR_ARCHS=	armv7 i386
NOT_FOR_ARCHS_REASON=	__int128 is not supported on this target
BUILD_DEPENDS=	gmake:devel/gmake

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	berkeley-abc
GH_TAGNAME=	0aabbb13f4a10cd8dc9c96ae3c743ec8fc3045a7
USE_LDCONFIG=	yes

CMAKE_ON=	ABC_SKIP_TESTS

BINARY_ALIAS=	make=${GMAKE}

PLIST_FILES=	bin/abc \
		lib/libabc.so

OPTIONS_DEFINE=		READLINE THREADS
OPTIONS_DEFAULT=	READLINE THREADS

READLINE_USES=			readline
READLINE_CONFIGURE_ENV=		ABC_READLINE_LIBRARIES="-L${LOCALBASE}/lib -lreadline"
READLINE_CONFIGURE_ENV_OFF=	ABC_USE_NO_READLINE=1
THREADS_CONFIGURE_ENV_OFF=	ABC_USE_NO_PTHREADS=1

do-install: # https://github.com/berkeley-abc/abc/issues/71
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/abc   ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${BUILD_WRKSRC}/libabc.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
