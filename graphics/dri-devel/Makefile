# Ports collection makefile for:	dri-devel
# Date created:				Wed Aug 21 14:47:34 PDT 2002
# Whom:					Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	5.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	anholt/dri-devel
DISTFILES=	${PORTNAME}-20031209.tar.bz2	\
		Mesa-newtree-5.1.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL hardware acceleration drivers snapshot for XFree86

WRKSRC=		${WRKDIR}/xc
BUILD_WRKSRC=	${WRKSRC}/lib/GL
USE_BZIP2=	yes
USE_X_PREFIX=	yes
MAKE_ENV=	FBSDCFLAGS="${CFLAGS}" FBSDCC="${CC}" FBSDCXX="${CXX}"
LATEST_LINK=	${PORTNAME}-devel

DRILIST=	ffb gamma i810 i830 mga r128 r200 radeon sis tdfx

ONLY_FOR_ARCHS=	alpha i386

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Install fails on alpha"
.endif

do-configure:
	@${RM} -f  ${WRKSRC}/config/cf/version.def
	@${RM} -f  ${WRKSRC}/config/cf/date.def
	@${TOUCH} ${WRKSRC}/config/cf/version.def
	@${TOUCH} ${WRKSRC}/config/cf/date.def
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} Makefile.boot
.for target in VerifyOS version.def Makefiles includes depend
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} -f xmakefile ${target}
.endfor

pre-build:
	cd ${WRKSRC}/config && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
.for i in ${DRILIST}
	${INSTALL_DATA} ${WRKSRC}/lib/GL/mesa/drivers/dri/${i}/${i}_dri.so \
		${PREFIX}/lib/modules/dri
.endfor

# Create package list:
	@cd ${PREFIX} && ${FIND} lib/modules/dri -type f | ${SORT} \
		>>${TMPPLIST}

.include <bsd.port.post.mk>
