# Ports collection makefile for:	dri-devel
# Date created:				Wed Aug 21 14:47:34 PDT 2002
# Whom:					Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	4.3.99.12.20031111
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	anholt/dri-devel
DISTNAME=	${PORTNAME}-20031111

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	OpenGL hardware acceleration drivers snapshot for XFree86

WRKSRC=		${WRKDIR}/xc
BUILD_WRKSRC=	${WRKSRC}/lib/GL
USE_BZIP2=	yes
USE_X_PREFIX=	yes
MAKE_ENV=	FBSDCFLAGS="${CFLAGS}" FBSDCC="${CC}" FBSDCXX="${CXX}"

DRILIST=	gamma/gamma_dri.so i810/i810_dri.so i830/i830_dri.so \
		mga/mga_dri.so r128/r128_dri.so r200/r200_dri.so \
		radeon/radeon_dri.so sis/sis_dri.so tdfx/tdfx_dri.so

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
	${INSTALL_DATA} ${WRKSRC}/lib/GL/mesa/src/drv/${i} \
		${PREFIX}/lib/modules/dri
.endfor

.include <bsd.port.mk>
