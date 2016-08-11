# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	libconcurrent
PORTVERSION=	0.0.20160303
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	t@tobik.me
COMMENT=	Tiny asymmetric-coroutine library

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nasm:devel/nasm

USE_GITHUB=	yes
GH_ACCOUNT=	sharow
# Rolling release
GH_TAGNAME=	f55d33a789a4b2c6267268ec2d44a245f766f500

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	EXAMPLES

MAKEFILE=	makefile
MAKE_ARGS=	LIBCONCURRENT_DESTDIR=${STAGEDIR}${PREFIX}
USES=		gmake compiler:c11

post-patch:
# Remove explicitly (re-)set C compiler and linker in libconcurrent's
# makefile.  The ports system will provide the correct ones.  This is
# needed on FreeBSD 9 where cc does not understand -std=c11.
	@${REINPLACE_CMD} 's/CC=cc//g' ${WRKSRC}/makefile
	@${REINPLACE_CMD} 's/LD=ld//g' ${WRKSRC}/makefile
# libconcurrent's makefile resets ${ARCH} internally and the ports
# system interferes with that for some reason, so replace it with a
# more neutral variant.
	@${REINPLACE_CMD} 's/ARCH/LIBCONCURRENT_ARCH/g' ${WRKSRC}/makefile
# Same with ${DESTDIR}
	@${REINPLACE_CMD} 's/DESTDIR/LIBCONCURRENT_DESTDIR/g' ${WRKSRC}/makefile

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
