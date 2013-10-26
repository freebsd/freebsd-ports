# $FreeBSD$

PORTNAME=	dragonegg46
PORTVERSION=	3.2
PORTREVISION=	2
CATEGORIES=	lang devel
MASTER_SITES=	http://llvm.org/releases/${PORTVERSION}/
DISTNAME=	dragonegg-${PORTVERSION}.src

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	GCC plugin to use the LLVM backend

CONFLICTS=	dragonegg46-devel-3*

BUILD_DEPENDS+=	llvm>=${PORTVERSION}:${PORTSDIR}/devel/llvm
RUN_DEPENDS+=	llvm>=${PORTVERSION}:${PORTSDIR}/devel/llvm

DEPRECATED=	Upgrade to dragonegg46-33 or dragonegg47-33
EXPIRATION_DATE=	2013-11-01

OPTIONS_DEFINE=	DOCS

USES=		compiler:features gmake
USE_GCC=	4.6
USE_LDCONFIG=	yes

DRAGONEGG_RELEASE=	${PORTVERSION:C/\.r[0-9]*//}
DRAGONEGG_SO=		dragonegg-${DRAGONEGG_RELEASE}.so
DRAGONEGG_PATH=		${GCC_LIBDIR}/${DRAGONEGG_SO}
GCC_LIBDIR=		lib/${CC}

ALL_TARGET=
MAKE_ARGS=	GCC=${LOCALBASE}/bin/${CC}

PLIST_FILES=		${GCC_LIBDIR}/${DRAGONEGG_SO}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=		README
.endif

.include <bsd.port.pre.mk>

.if ${COMPILER_FEATURES:Mlibc++}
IGNORE= dragonegg can't work if LLVM was built with libc++
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

.include <bsd.port.post.mk>
