# New ports collection makefile for:    Gorm
# Date created:         15 Mar 2002
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gorm
PORTVERSION=	0.2.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP} \
		ftp://ftp.gnustep.org/pub/gnustep/%SUBDIR%/
DISTNAME=	Gorm-${PORTVERSION}
MASTER_SITE_SUBDIR=	dev-apps

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Graphical Object Relationship Modeller

BUILD_DEPENDS=	${BACKBUNDLEDIR}/libgnustep-back:${PORTSDIR}/x11-toolkits/gnustep-back
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcallback.a:${PORTSDIR}/devel/ffcall
RUN_DEPENDS=	${BACKBUNDLEDIR}/libgnustep-back:${PORTSDIR}/x11-toolkits/gnustep-back

PREFIX=		${LOCALBASE}/GNUstep
USE_GMAKE=	yes
MAKEFILE=	
MAKE_FLAGS=	GUI_BACKEND_LIB=back
ALL_TARGET=
NO_MTREE=	yes
USE_GCC=	3.2

BACKBUNDLEDIR=	${PREFIX}/System/Library/Bundles/libgnustep-back.bundle/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif

PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} OPSYS=${OPSYS:L} VERSION=${PORTVERSION}

do-build:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

do-install:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
