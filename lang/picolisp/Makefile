PORTNAME=	picolisp
PORTVERSION=	23.12
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://software-lab.de/
DISTNAME=	picoLisp-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Minimal Lisp interpreter with a focus on simplicity
WWW=		https://picolisp.com

LICENSE=	MIT

LIB_DEPENDS=	libffi.so:devel/libffi

ONLY_FOR_ARCHS=	amd64

USES=		gmake llvm:17,lib pkgconfig readline ssl tar:tgz

WRKSRC=		${WRKDIR}/pil21/src

post-patch:
	${REINPLACE_CMD} \
		-e 's|clang|clang${LLVM_VERSION}|' \
		-e 's|opt|opt${LLVM_VERSION}|' \
		-e 's|llc|llc${LLVM_VERSION}|' \
		-e 's|llvm-link|llvm-link${LLVM_VERSION}|' \
		-e 's|llvm-config|${LLVM_CONFIG}|' \
		-e '/^MAIN/s|$$| -L${LOCALBASE}/lib|' \
		-e '/^.SILENT:/d' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -i '' -e 's|/usr|${PREFIX}|g' ${WRKSRC}/../bin/*

post-build:
	${GZIP_CMD} ${WRKSRC}/../man/man1/picolisp.1 ${WRKSRC}/../man/man1/pil.1

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/picolisp
	cd ${WRKSRC}/.. && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/picolisp "! -name '*.bak'"
	${RM} -r ${STAGEDIR}${PREFIX}/lib/picolisp/src ${STAGEDIR}${PREFIX}/lib/picolisp/test
	${FIND} ${STAGEDIR}${PREFIX}/lib/picolisp/bin -exec ${CHMOD} a+x {} \;
	${LN} -s ../lib/picolisp/bin/picolisp ${STAGEDIR}${PREFIX}/bin/
	${LN} -s ../lib/picolisp/bin/pil ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1
	${LN} -s ../../lib/picolisp/man/man1/picolisp.1.gz ${STAGEDIR}/${PREFIX}/share/man/man1
	${LN} -s ../../lib/picolisp/man/man1/pil.1.gz ${STAGEDIR}/${PREFIX}/share/man/man1

.include <bsd.port.mk>
