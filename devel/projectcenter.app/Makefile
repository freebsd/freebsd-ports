# New ports collection makefile for:    ProjectCenter
# Date created:         22 Sep 2000
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	projectcenter.app
PORTVERSION=	0.3.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/dev-apps/
.if defined(GNUSTEP_GUI_DEVEL)
PKGNAMESUFFIX?=	-devel
.endif
DISTNAME=	ProjectCenter-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

.if defined(GNUSTEP_GUI_DEVEL)
BUILD_DEPENDS=	${BACKBUNDLEDIR}/libgnustep-back:${PORTSDIR}/x11-toolkits/gnustep-back
RUN_DEPENDS=	${BACKBUNDLEDIR}/libgnustep-back:${PORTSDIR}/x11-toolkits/gnustep-back
.else
BUILD_DEPENDS=	${XGPSBUNDLEDIR}/libgnustep-xgps:${PORTSDIR}/x11-toolkits/gnustep-xgps
RUN_DEPENDS=	${XGPSBUNDLEDIR}/libgnustep-xgps:${PORTSDIR}/x11-toolkits/gnustep-xgps
.endif

PREFIX=		${LOCALBASE}/GNUstep
WRKSRC=		${WRKDIR}/ProjectCenter
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ENV=	ADDITIONAL_INCLUDE_DIRS="-I${WRKSRC}" \
		ADDITIONAL_LIB_DIRS="-L${WRKSRC}/PCLib/shared_obj/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu"
ALL_TARGET=
NO_MTREE=	yes

BACKBUNDLEDIR=	${PREFIX}/System/Library/Bundles/libgnustep-back.bundle/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu
XGPSBUNDLEDIR=	${PREFIX}/System/Library/Bundles/libgnustep-xgps.bundle/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif

PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} OPSYS=${OPSYS:L} VERSION=${PORTVERSION}

# XXX This is ugly beyond measure. Don't tell anyone I did this.
post-extract:
	${LN} -sf ${WRKSRC}/PCLib/*.h ${WRKSRC}/ProjectCenter

# Quick workaround until I find out how to set the real path in the code
post-patch:
.for file in PCLib/PCBundleLoader.m ProjectCenter/PCAppController.m
	${PERL} -pi -e "s:@\"/usr/GNUstep:@\"${PREFIX}:g" ${WRKSRC}/${file}
.endfor

do-build:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

do-install:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
