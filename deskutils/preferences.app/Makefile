# New ports collection makefile for:   preferences.app
# Date created:         04 Feb 2003
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	preferences.app
PORTVERSION=	1.2.0
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	prefsapp
DISTNAME=	Preferences-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org

BUILD_DEPENDS=	${BACKBUNDLEDIR}/libgnustep-back:${PORTSDIR}/x11-toolkits/gnustep-back
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcallback.a:${PORTSDIR}/devel/ffcall
RUN_DEPENDS=	${BACKBUNDLEDIR}/libgnustep-back:${PORTSDIR}/x11-toolkits/gnustep-back

USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
PREFIX=		${LOCALBASE}/GNUstep
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=
NO_MTREE=	yes
MODIFY=		GNUmakefile.preamble PrefsModule/GNUmakefile.preamble \
		Modules/Keyboard/GNUmakefile.preamble \
		Modules/PrefsApp/GNUmakefile.preamble

BACKBUNDLEDIR=	${PREFIX}/System/Library/Bundles/libgnustep-back.bundle/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif

PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} OPSYS=${OPSYS:L}

post-patch:
.for i in ${MODIFY}
	@${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}.sed
	${SED} -e "s= -Werror==" ${WRKSRC}/${i}.sed > ${WRKSRC}/${i}
.endfor

do-build:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

do-install:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
