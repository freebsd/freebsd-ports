# ex:ts=8
# Ports collection makefile for:  stlport
# Date Created:			  2 December 1998
# Whom:				  Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	stlport
PORTVERSION=	5.1.5
PORTREVISION=	1
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
COMPILER?=	gcc
MAKEFILE=	${COMPILER}.mak
ALL_TARGET=	install
MAKE_ARGS+=	INSTALLDIR=${PREFIX} PTHREAD_CFLAGS=${PTHREAD_CFLAGS} 		\
		PTHREAD_LIBS=${PTHREAD_LIBS}
PLIST_SUB+=	COMPILER=${COMPILER} VER=${PORTVERSION} V2=${PORTVERSION:R}	\
		V1=${PORTVERSION:R:R}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lib-motif=${COMPILER}
USE_LDCONFIG=	yes
PORTDOCS=	*

OPTIONS=	SHORT_STRING_OPTIM "Enable short string optimization." on 	\
		PTR_SPECIALIZATIONS "Use pointer types specializations." off 	\
		TEMPLATE_EXPRESSION "Use template expressions for string." off 	\
		BOOST_SUPPORT "Use Boost type traits." off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SHORT_STRING_OPTIM)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-no-short-string-optim-user_config.h.diff
.endif

.if defined(WITH_PTR_SPECIALIZATIONS)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ptr_spec-user_config.h.diff
.endif

.if defined(WITH_TEMPLATE_EXPRESSION)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-templ-expr-user_config.h.diff
.endif

.if defined(WITH_BOOST_SUPPORT)
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
.if !defined(NOPORTDOCS)
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
