# Created by: Josh Gilliam <josh@quick.net>
# $FreeBSD$

PORTNAME=	stlport
PORTVERSION=	5.1.7
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/STLport/STLport%20${PORTVERSION}
PKGNAMESUFFIX=	-${COMPILER}
DISTNAME=	STLport-${PORTVERSION:S/.b/-b/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adaptation of SGI\'s Standard Template Library

USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/STLport-${PORTVERSION:S/.b/b/}/build/lib
PATCH_WRKSRC=	${WRKDIR}/STLport-${PORTVERSION:S/.b/b/}
USE_GMAKE=	yes
USE_GCC=	any
COMPILER?=	gcc
MAKEFILE=	${COMPILER}.mak
ALL_TARGET=	install
MAKE_ARGS+=	INSTALLDIR=${PREFIX}
PLIST_SUB+=	COMPILER=${COMPILER} VER=${PORTVERSION} V2=${PORTVERSION:R}	\
		V1=${PORTVERSION:R:R}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lib-motif=${COMPILER}
USE_LDCONFIG=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	SHORT_STRING_OPTIM PTR_SPECIALIZATIONS TEMPLATE_EXPRESSION BOOST DOCS
OPTIONS_DEFAULT=	SHORT_STRING_OPTIM
SHORT_STRING_OPTIM_DESC=	Enable short string optimization
PTR_SPECIALIZATIONS_DESC=	Use pointer types specializations
TEMPLATE_EXPRESSION_DESC=	Use template expressions for string
BOOST_DESC=	Use Boost type traits

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if empty(PORT_OPTIONS:MSHORT_STRING_OPTIM)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-no-short-string-optim-user_config.h.diff
.endif

.if ${PORT_OPTIONS:MPTR_SPECIALIZATIONS}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ptr_spec-user_config.h.diff
.endif

.if ${PORT_OPTIONS:MTEMPLATE_EXPRESSION}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-templ-expr-user_config.h.diff
.endif

.if ${PORT_OPTIONS:MBOOST}
EXTRA_PATCHES+= ${PATCHDIR}/extra-patch-boost-support-user_config.h.diff
MAKE_ENV+= STLP_BUILD_BOOST_PATH=${LOCALBASE}/include
BUILD_DEPENDS+= ${LOCALBASE}/include/boost/config/stdlib/stlport.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS+= ${LOCALBASE}/include/boost/config/stdlib/stlport.hpp:${PORTSDIR}/devel/boost-libs
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|gcc|${COMPILER}|' ${WRKSRC}/gcc.mak      \
	${WRKSRC}/../test/unit/gcc.mak
.for lib in stlport stlportg stlportstlg
	${REINPLACE_CMD} -e 's|-l${lib}$$|-l${lib}_${COMPILER}|'        \
		${PATCH_WRKSRC}/build/Makefiles/gmake/app/gcc.mak
.endfor
.if ${ARCH} != i386
. for sdir in app lib
	# Cannot build a shared object with libsupc++
	${REINPLACE_CMD} -e 's|-lsupc++|-lstdc++|'		\
		${PATCH_WRKSRC}/build/Makefiles/gmake/${sdir}/gcc.mak
. endfor
.endif

do-install:
	${MKDIR} "${PREFIX}/include/stlport/"
	(cd ${PATCH_WRKSRC}/stlport/ && ${COPYTREE_SHARE} \* ${PREFIX}/include/stlport/)
	(cd ${PATCH_WRKSRC}/lib; ${TAR} cf - *) | (cd ${PREFIX}/lib; ${TAR} xf -)
	${CHOWN} -h ${BINOWN}:${BINGRP} ${PREFIX}/lib/libstlport*
	${FIND} ${PREFIX}/include/stlport -name \*.orig -delete
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PATCH_WRKSRC}/doc/* ${DOCSDIR}
.endif

.ifndef(PACKAGE_BUILDING)
regression-test:
	(cd ${WRKSRC}/../test/unit &&	\
	${SETENV} STLPORT_LIB_DIR="${PATCH_WRKSRC}/lib"	\
	${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET} && \
	(../../../bin/stl_unit_test || ${TRUE}) &&	\
	(../../../bin-g/stl_unit_test  || ${TRUE}) )
.endif

.include <bsd.port.post.mk>
