# New ports collection makefile for:    gnustep-base
# Date created:         17 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-base
PORTVERSION=	1.5.1
CATEGORIES=	lang devel
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/core/ \
		http://archive.progeny.com/gnustep/core/ \
		ftp://ftp.easynet.nl/mirror/GNUstep/core/

MAINTAINER=	dinoex@FreeBSD.org

BUILD_DEPENDS=	${SYSLIBDIR}/libobjc.so:${PORTSDIR}/lang/gnustep-objc
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	${SYSLIBDIR}/libobjc.so:${PORTSDIR}/lang/gnustep-objc

BREAKS_IF_PEDANTIC=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
BROKEN=		"Sorry, this port does not work on FreeBSD-2.2.x"
.endif

PREFIX=		${LOCALBASE}/GNUstep
PLIST_SUB+=	LOCALBASE=${LOCALBASE}
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-procfs
CONFIGURE_TARGET=
USE_GMAKE=	yes
MAKEFILE=
MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
NO_MTREE=	yes
CFLAGS+=	-I${LOCALBASE}/include/libxml2/libxml

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif
PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} OPSYS=${OPSYS:L} VERSION=${PORTVERSION} \
		MAJORVERSION=${PORTVERSION:C/([0-9]).*/\1/1}
ETCDIR=		${LOCALBASE}/etc
SYSTEMDIR=	${PREFIX}/System
SYSLIBDIR=	${SYSTEMDIR}/Libraries/${GNU_ARCH}/${OPSYS:L}

post-extract:
	@${SED} -e "s=%%PREFIX%%=${LOCALBASE}=" ${FILESDIR}/GNUstep.sh \
		> ${WRKSRC}/GNUstep.sh

do-configure:
	@(cd ${WRKSRC}; . ${SYSTEMDIR}/Makefiles/GNUstep.sh; \
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
	@(cd ${WRKSRC}; . ${SYSTEMDIR}/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

do-install:
	@(cd ${WRKSRC}; . ${SYSTEMDIR}/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

post-install:
	-@${MKDIR} ${ETCDIR}/rc.d
	${INSTALL_SCRIPT} ${FILESDIR}/GNUstep.sh ${ETCDIR}/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/GNUstep.sh ${ETCDIR}/rc.d
	${INSTALL_DATA} ${FILESDIR}/gdomap_if ${ETCDIR}

.include <bsd.port.post.mk>
