# $FreeBSD$

PORTNAME=	dragonegg46
PORTVERSION=	3.4.r${SVN_REV}
PORTREVISION=	2
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMESUFFIX=	-devel
DISTNAME=	dragonegg-${PORTVERSION}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	GCC plugin to use the LLVM backend

BUILD_DEPENDS+=	llvm-config${LLVM_SUFFIX}:${PORTSDIR}/devel/llvm-devel
RUN_DEPENDS+=	llvm-config${LLVM_SUFFIX}:${PORTSDIR}/devel/llvm-devel

LLVM_SUFFIX=	-devel

OPTIONS_DEFINE=	DOCS

USES=		compiler:features gmake
USE_BZIP2=	yes
USE_GCC=	4.6
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}
UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

DRAGONEGG_RELEASE=	${PORTVERSION:C/\.r[0-9]*//}svn
DRAGONEGG_SO=		dragonegg-${DRAGONEGG_RELEASE}.so
DRAGONEGG_PATH=		${GCC_LIBDIR}/${DRAGONEGG_SO}
GCC_LIBDIR=		lib/${CC}

ALL_TARGET=
MAKE_ARGS=	GCC=${LOCALBASE}/bin/${CC} LLVM_CONFIG=llvm-config${LLVM_SUFFIX}

.include "${.CURDIR}/../../devel/llvm-devel/Makefile.svn_rev"

PLIST_FILES=		${GCC_LIBDIR}/${DRAGONEGG_SO}

.include <bsd.port.options.mk>

PORTDOCS=		README

.include <bsd.port.pre.mk>

.if ${COMPILER_FEATURES:Mlibc++}
IGNORE=	"Dragonegg can't work if LLVM was built with libc++"
.endif

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
	    http://llvm.org/svn/llvm-project/dragonegg/trunk \
	    ${WRKDIR}/${DISTNAME}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
.if ${USER} == brooks || ${USER} == bed22
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    brooks@freefall.freebsd.org:public_distfiles/
.endif
.endif

post-patch:
	${REINPLACE_CMD} -e 's/%%CC%%/${CC}/' \
	    -e 's#%%PLUGINPATH%%#${LOCALBASE}/${DRAGONEGG_PATH}#' \
	    -e 's/arg-dragonegg/arg-dragonegg-${DRAGONEGG_RELEASE}/' \
	    ${WRKSRC}/README

do-install:
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/${GCC_LIBDIR}
	${INSTALL_LIB} ${WRKSRC}/dragonegg.so \
	    ${STAGEDIR}${LOCALBASE}/${GCC_LIBDIR}/${DRAGONEGG_SO}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
