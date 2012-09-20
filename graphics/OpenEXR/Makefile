# New ports collection makefile for:	OpenEXR
# Date created:				2003/01/26
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	OpenEXR
PORTVERSION=	1.7.0
DISTNAME=	${PORTNAME:L}-${PORTVERSION}
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high dynamic-range (HDR) image file format

LIB_DEPENDS=	Half.6:${PORTSDIR}/graphics/ilmbase

USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--enable-imfexamples

OPTIONS_DEFINE=	LARGE_STACK
LARGE_STACK_DESC=	Enable sys-dependant large stack optimizations

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLARGE_STACK}
CONFIGURE_ARGS+=--enable-large-stack
.endif

# must be explicitely linked with -l{thr|pthread}
LDFLAGS+=	${PTHREAD_LIBS}

WRKSRC=		${WRKDIR}/${DISTNAME}

regression-test regression test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

# IlmImfTest hangs indefinitely
#
#.if defined(PACKAGE_BUILDING)
#.if ${ARCH} != sparc64 || ${OSVERSION} >= 700055
#.if ${ARCH} != amd64 || ${OSVERSION} < 800000
#pre-install:	test
#.endif
#.endif
#.endif

.include <bsd.port.post.mk>
