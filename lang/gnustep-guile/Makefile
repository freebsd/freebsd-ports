# New ports collection makefile for:    gnustep-guile
# Date created:         24 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-guile
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNUSTEP} \
		ftp://ftp.gnustep.org/pub/gnustep/%SUBDIR%/
MASTER_SITE_SUBDIR=	libs

MAINTAINER=	dinoex@FreeBSD.org

BUILD_DEPENDS=	${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/lang/gnustep-base
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcallback.a:${PORTSDIR}/devel/ffcall
RUN_DEPENDS=	${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/lang/gnustep-base
LIB_DEPENDS=	guile.10:${PORTSDIR}/lang/guile

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
BROKEN=		"Sorry, this port does not work on FreeBSD-2.2.x"
.endif

PREFIX=		${LOCALBASE}/GNUstep
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
USE_GMAKE=	yes
MAKEFILE=
MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
NO_MTREE=	yes

MAN1=	greg.1

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif
PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} OPSYS=${OPSYS:L} VERSION=${PORTVERSION}

COMBOLIBDIR=	${PREFIX}/System/Libraries/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu

do-configure:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
	    if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
		INSTALL_DATA="${INSTALL} -c" \
		INSTALL_PROGRAM="${INSTALL} -c" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; then \
		    ${ECHO} "===>  Script \"${CONFIGURE_SCRIPT}\" failed: here are the contents of \"${CONFIGURE_LOG}\""; \
		    ${CAT} ${CONFIGURE_LOG}; \
		    ${ECHO} "(end of \"${CONFIGURE_LOG}\")"; \
		    ${FALSE}; \
	    fi)

do-build:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

do-install:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
