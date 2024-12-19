PORTNAME=	io
PORTVERSION=	2017.09.06
PORTREVISION=	11
CATEGORIES=	lang

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Small prototype-based programming language
WWW=		https://iolanguage.org

LICENSE=	BSD3CLAUSE

BROKEN_armv6=		fails to compile: ucontext.h: expected parameter declarator
BROKEN_armv7=		fails to compile: Coro.c:392:2: no member named 'arm_r0' in 'mcontext_t'

CONFLICTS=	io-devel

USES=		cmake:noninja compiler:c11 ssl

USE_GITHUB=	yes
GH_ACCOUNT=	stevedekorte

MAKE_JOBS_UNSAFE=yes
USE_LDCONFIG=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_GROUP=	ADDONS
OPTIONS_SUB=	yes

.include "${.CURDIR}/Makefile.addons"

.include <bsd.port.pre.mk>

# disable SSE on non-x86 archs
.if ${ARCH} != amd64 && ${ARCH} != i386
EXTRA_PATCHES+=		${PATCHDIR}/extra-patch-CMakeLists.txt
.endif

post-patch:
	${REINPLACE_CMD} -e 's/^[ ]*add_subdirectory/#&/' \
		${WRKSRC}/addons/CMakeLists.txt
	${RM} ${WRKSRC}/modules/FindFreetype.cmake
.for addon in ${ADDONS}
	${ECHO} "add_subdirectory(${addon})" >> ${WRKSRC}/addons/CMakeLists.txt
.endfor
	${FIND} ${WRKSRC}/addons -name "*.bak" -o -name "*.orig" -delete

post-install:
	${FIND} -d ${STAGEDIR}${PREFIX}/lib/io/addons -type d -empty -delete
	${FIND} ${STAGEDIR}${PREFIX}/lib/io/addons -type f -name "*.so" -exec \
		${STRIP_CMD} {} \;
	${MKDIR}  ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${MKDIR}  ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/SyntaxHighlighters
.for syn in "Emacs IntelliJ JEdit Kate Scintilla Vim"
	cd ${WRKSRC}/extras/SyntaxHighlighters && \
	    ${COPYTREE_SHARE} ${syn} ${STAGEDIR}${DATADIR}/SyntaxHighlighters
.endfor

do-test:
	cd ${BUILD_WRKSRC} && \
	    ./_build/binaries/io ${WRKSRC}/libs/iovm/tests/correctness/run.io

.include <bsd.port.post.mk>
