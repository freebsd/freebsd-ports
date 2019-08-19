# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nspr
DISTVERSION=	4.22
CATEGORIES=	devel
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/v${PORTVERSION}/src

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Platform-neutral API for system level and libc like functions

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe gmake pathfix
CPE_VENDOR=	mozilla
CPE_PRODUCT=	netscape_portable_runtime
WRKSRC_SUBDIR=	nspr
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG TEST

DEBUG_CONFIGURE_ENABLE=debug

post-patch:
# Do not install tools to build itself
	@${REINPLACE_CMD} -e '/RELEASE_BINS/d' \
		${WRKSRC}/pr/src/misc/Makefile.in

post-build-TEST-on:
	@${DO_MAKE_BUILD} -C ${BUILD_WRKSRC}/lib/tests
	@${DO_MAKE_BUILD} -C ${BUILD_WRKSRC}/pr/tests
	@${LN} -fs libmy.so.1 ${BUILD_WRKSRC}/pr/tests/dll/libmy.so

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

do-test-TEST-on:
	${TEST_WRKSRC}/lib/tests/string
	${TEST_WRKSRC}/lib/tests/base64t
	cd ${TEST_WRKSRC}/pr/tests && ${WRKSRC}/pr/tests/runtests.sh
	# The test below is commented out, because arena requires
	# command-line arguments. If you can provide reasonable values
	# for it, please contact ${MAINTAINER}. Thank you.
	#	${TEST_WRKSRC}/lib/tests/arena
	#

.include <bsd.port.mk>
