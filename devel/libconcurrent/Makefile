PORTNAME=	libconcurrent
PORTVERSION=	0.0.20210731
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny asymmetric-coroutine library

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	nasm:devel/nasm

USES=		gmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	sharow
# Rolling release
GH_TAGNAME=	50fe214cac8e17a8bdafdcf37c20365cbbc0caa4

MAKEFILE=	makefile
MAKE_ARGS=	LIBCONCURRENT_DESTDIR=${STAGEDIR}${PREFIX}
TEST_TARGET=	test

OPTIONS_DEFINE=	EXAMPLES

post-patch:
# libconcurrent's makefile resets ${ARCH} internally and the ports
# system interferes with that for some reason, so replace it with a
# more neutral variant.  Same with ${DESTDIR}.
	@${REINPLACE_CMD} -e 's/ARCH/LIBCONCURRENT_ARCH/g' \
		-e 's/DESTDIR/LIBCONCURRENT_DESTDIR/g' \
		${WRKSRC}/makefile

post-patch-EXAMPLES-on:
# Fix examples makefile to work out-of-tree
	@${REINPLACE_CMD} 's|INCDIR+=-I../include|INCDIR+=-I${PREFIX}/include|g' \
		${WRKSRC}/examples/makefile
	@${REINPLACE_CMD} 's|-L../|-L${PREFIX}/lib|g' \
		${WRKSRC}/examples/makefile

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
