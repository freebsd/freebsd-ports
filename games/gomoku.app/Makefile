# New ports collection makefile for:    Gomoku
# Date created:         19 Sep 2000
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gomoku.app
PORTVERSION=	1.1.0
CATEGORIES=	games
MASTER_SITES=	http://www.gnustep.it/nicola/Applications/Gomoku/
DISTNAME=	Gomoku-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/GNUstep/System/Makefiles/GNUstep.sh:${PORTSDIR}/devel/gnustep
RUN_DEPENDS=	${LOCALBASE}/GNUstep/System/Makefiles/GNUstep.sh:${PORTSDIR}/devel/gnustep

PREFIX=		${LOCALBASE}/GNUstep
USE_NEWGCC=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=
NO_MTREE=	yes

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif

PLIST_SUB+=	GNU_ARCH=${GNU_ARCH}

do-build:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

do-install:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
