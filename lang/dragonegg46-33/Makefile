# $FreeBSD$

PORTNAME=	dragonegg
PORTVERSION=	3.3
CATEGORIES=	lang devel
MASTER_SITES=	http://llvm.org/releases/${PORTVERSION}/
PKGNAMESUFFIX=	${USE_GCC:S/.//g}
DISTNAME=	dragonegg-${PORTVERSION}.src

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	GCC plugin to use the LLVM backend

CONFLICTS=	dragonegg46-devel-3.3*

BUILD_DEPENDS+=	llvm-config${LLVM_SUFFIX}:${PORTSDIR}/devel/llvm${LLVM_SUFFIX}
RUN_DEPENDS+=	${CC}:${PORTSDIR}/lang/gcc \
		llvm-config${LLVM_SUFFIX}:${PORTSDIR}/devel/llvm${LLVM_SUFFIX}

LLVM_SUFFIX=	${PORTVERSION:S/.//g}

OPTIONS_DEFINE=	DOCS

USE_GCC?=	4.6
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}-${LLVM_SUFFIX}
LATEST_LINK=	${UNIQUENAME}
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}

DRAGONEGG_RELEASE=	${PORTVERSION:C/\.r[0-9]*//}
DRAGONEGG_SO=		dragonegg-${DRAGONEGG_RELEASE}.so
DRAGONEGG_PATH=		${GCC_LIBDIR}/${DRAGONEGG_SO}
GCC_LIBDIR=		lib/${CC}

ALL_TARGET=
MAKE_ARGS=	GCC=${LOCALBASE}/bin/${CC} LLVM_CONFIG=llvm-config33

PLIST_FILES=		${GCC_LIBDIR}/${DRAGONEGG_SO}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=		README
.endif

post-patch:
	${REINPLACE_CMD} -e 's/%%CC%%/${CC}/' \
	    -e 's#%%PLUGINPATH%%#${LOCALBASE}/${DRAGONEGG_PATH}#' \
	    -e 's/arg-dragonegg/arg-dragonegg-${DRAGONEGG_RELEASE}/' \
	    ${WRKSRC}/README

do-install:
	${INSTALL_LIB} ${WRKSRC}/dragonegg.so \
	    ${LOCALBASE}/${GCC_LIBDIR}/${DRAGONEGG_SO}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

test:
	${CC} -fplugin=${PREFIX}/${DRAGONEGG_PATH} ${FILESDIR}/hello.c \
	    -o ${WRKDIR}/hello
	if [ "`${WRKDIR}/hello`" != "hello" ]; then \
		${ECHO_CMD} wrong answer from ${WRKDIR}/test/hello ;\
		${FALSE} ;\
	fi

.include <bsd.port.mk>
