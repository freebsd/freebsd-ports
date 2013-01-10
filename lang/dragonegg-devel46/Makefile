# $FreeBSD$
#

PORTNAME=	dragonegg46
PORTVERSION=	3.3.r${SVN_REV}
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMESUFFIX=	-devel
DISTNAME=	dragonegg-${PORTVERSION}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	GCC plugin to use the LLVM backend

# XXX: not entierly sure if llvm-devel is a depend
BUILD_DEPENDS+=	llvm-devel>=${PORTVERSION}:${PORTSDIR}/devel/llvm-devel
RUN_DEPENDS+=	${CC}:${PORTSDIR}/lang/gcc \
		llvm-devel>=${PORTVERSION}:${PORTSDIR}/devel/llvm-devel

OPTIONS_DEFINE=	DOCS

USE_BZIP2=	yes
USE_GCC=	4.6
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

DRAGONEGG_RELEASE=	${PORTVERSION:C/\.r[0-9]*//}
DRAGONEGG_SO=		dragonegg-${DRAGONEGG_RELEASE}.so
DRAGONEGG_PATH=		${GCC_LIBDIR}/${DRAGONEGG_SO}
GCC_LIBDIR=		lib/${CC}

ALL_TARGET=
MAKE_ARGS=	GCC=${LOCALBASE}/bin/${CC}

.include "${.CURDIR}/../../devel/llvm-devel/Makefile.svn_rev"

PLIST_FILES=		${GCC_LIBDIR}/${DRAGONEGG_SO}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=		README
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
	${INSTALL_LIB} ${WRKSRC}/dragonegg.so \
	    ${LOCALBASE}/${GCC_LIBDIR}/${DRAGONEGG_SO}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
