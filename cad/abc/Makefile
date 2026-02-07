PORTNAME=	abc
DISTVERSION=	g20260104
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
GH_TAGNAME=	c18b9a24
USE_LDCONFIG=	yes

CMAKE_ON=	ABC_SKIP_TESTS

BINARY_ALIAS=	make=${GMAKE}

PLIST_FILES=	bin/${PORTNAME} \
		lib/lib${PORTNAME}.so

OPTIONS_DEFINE=		READLINE THREADS
OPTIONS_DEFAULT=	READLINE THREADS

READLINE_USES=			readline
READLINE_CONFIGURE_ENV=		ABC_READLINE_LIBRARIES="-L${LOCALBASE}/lib -lreadline"
READLINE_CONFIGURE_ENV_OFF=	ABC_USE_NO_READLINE=1
THREADS_CONFIGURE_ENV_OFF=	ABC_USE_NO_PTHREADS=1

do-install: # https://github.com/berkeley-abc/abc/issues/71
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
