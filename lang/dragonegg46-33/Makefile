# $FreeBSD$

PORTNAME=	dragonegg
PORTVERSION=	3.3
PORTREVISION=	4
CATEGORIES=	lang devel
MASTER_SITES=	http://llvm.org/releases/${PORTVERSION}/
PKGNAMESUFFIX=	${USE_GCC:S/.//g}-${LLVM_SUFFIX}
DISTNAME=	dragonegg-${PORTVERSION}.src

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	GCC plugin to use the LLVM backend

CONFLICTS=	dragonegg46-devel-3.3*

BUILD_DEPENDS+=	llvm-config${LLVM_SUFFIX}:${PORTSDIR}/devel/llvm${LLVM_SUFFIX}
RUN_DEPENDS+=	llvm-config${LLVM_SUFFIX}:${PORTSDIR}/devel/llvm${LLVM_SUFFIX}

LLVM_SUFFIX=	${PORTVERSION:S/.//g}

OPTIONS_DEFINE=	DOCS

USES=		compiler:features gmake
USE_GCC?=	4.6
USE_LDCONFIG=	yes
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}
UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

DRAGONEGG_RELEASE=	${PORTVERSION:C/\.r[0-9]*//}
DRAGONEGG_SO=		dragonegg-${DRAGONEGG_RELEASE}.so
DRAGONEGG_PATH=		${GCC_LIBDIR}/${DRAGONEGG_SO}
GCC_LIBDIR=		lib/${CC}

ALL_TARGET=
MAKE_ARGS=	GCC=${LOCALBASE}/bin/${CC} LLVM_CONFIG=llvm-config${LLVM_SUFFIX}

PLIST_FILES=		${GCC_LIBDIR}/${DRAGONEGG_SO}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=		README
.endif

.include <bsd.port.pre.mk>

.if ${COMPILER_FEATURES:Mlibc++}
IGNORE= "Dragonegg can't work if LLVM was built with libc++"
.endif

post-patch:
	${REINPLACE_CMD} -e 's/%%CC%%/${CC}/' \
	    -e 's#%%PLUGINPATH%%#${LOCALBASE}/${DRAGONEGG_PATH}#' \
	    -e 's/arg-dragonegg/arg-dragonegg-${DRAGONEGG_RELEASE}/' \
	    ${WRKSRC}/README

do-install:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/${GCC_LIBDIR}
	${INSTALL_LIB} ${WRKSRC}/dragonegg.so \
	    ${STAGEDIR}${LOCALBASE}/${GCC_LIBDIR}/${DRAGONEGG_SO}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

test:
	${CC} -fplugin=${PREFIX}/${DRAGONEGG_PATH} ${FILESDIR}/hello.c \
	    -o ${WRKDIR}/hello
	if [ "`${WRKDIR}/hello`" != "hello" ]; then \
		${ECHO_CMD} wrong answer from ${WRKDIR}/test/hello ;\
		${FALSE} ;\
	fi

.include <bsd.port.post.mk>
