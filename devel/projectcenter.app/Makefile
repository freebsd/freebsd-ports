# New ports collection makefile for:    ProjectCenter
# Date created:         22 Sep 2000
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	projectcenter.app
PORTVERSION=	0.2.0
CATEGORIES=	devel
MASTER_SITES=	http://www.projectcenter.ch/
DISTNAME=	ProjectCenter-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/GNUstep/System/Makefiles/GNUstep.sh:${PORTSDIR}/devel/gnustep
RUN_DEPENDS=	${LOCALBASE}/GNUstep/System/Makefiles/GNUstep.sh:${PORTSDIR}/devel/gnustep

PREFIX=		${LOCALBASE}/GNUstep
WRKSRC=		${WRKDIR}/ProjectCenter
USE_NEWGCC=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ENV=	ADDITIONAL_INCLUDE_DIRS="-I${WRKSRC}" \
		ADDITIONAL_LIB_DIRS="-L${WRKSRC}/PCLib/shared_obj/${GNU_ARCH}/freebsdelf/gnu-gnu-gnu-xgps"
ALL_TARGET=
NO_MTREE=	yes

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif

PLIST_SUB+=	GNU_ARCH=${GNU_ARCH}

# XXX This is ugly beyond measure. Don't tell anyone I did this.
post-extract:
	${LN} -sf ${WRKSRC}/PCLib/*.h ${WRKSRC}/ProjectCenter

# Quick workaround until I found out how to set the real path in the code
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
