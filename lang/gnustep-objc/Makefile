# New ports collection makefile for:    gnustep-objc
# Date created:         17 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-objc
PORTVERSION=	1.2.2
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP} \
		ftp://ftp.gnustep.org/pub/gnustep/%SUBDIR%/
MASTER_SITE_SUBDIR=	libs

MAINTAINER=	dinoex@FreeBSD.org

BUILD_DEPENDS=	${SYSTEMDIR}/Makefiles/GNUstep.sh:${PORTSDIR}/devel/gnustep-make \
		${LOCALBASE}/lib/libcallback.a:${PORTSDIR}/devel/ffcall
RUN_DEPENDS=	${SYSTEMDIR}/Makefiles/GNUstep.sh:${PORTSDIR}/devel/gnustep-make

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
BROKEN=		"Sorry, this port does not work on FreeBSD-2.2.x"
.endif

PREFIX=		${LOCALBASE}/GNUstep
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=
NO_MTREE=	yes

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif
PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} OPSYS=${OPSYS:L} VERSION=${PORTVERSION} \
		MAJORVERSION=${PORTVERSION:C/([0-9]).*/\1/1}

SYSTEMDIR=	${LOCALBASE}/GNUstep/System

do-build:
	(cd ${WRKSRC}; . ${SYSTEMDIR}/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

do-install:
	@(cd ${WRKSRC}; . ${SYSTEMDIR}/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
