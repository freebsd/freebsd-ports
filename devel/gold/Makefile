# New ports collection makefile for:    gold
# Date created:         16 Aug 2009
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gold
PORTVERSION=	1.9.0.2009.09.16
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.dinoex.de/pub/approved/
DISTNAME=	binutils-${PORTNAME}-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Google Releases New and Improved GCC Linker

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes

WRKSRC=		${WRKDIR}/binutils
PLIST_FILES=	bin/ld-new

.include <bsd.port.pre.mk>

.if defined(WITH_NLS)
USE_GETTEXT=	yes
CFLAGS+=	-I${LOCALBASE}/include
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

do-configure:
.for i in . libiberty gold
	-cd ${WRKSRC}/${i} && \
		${SET_LATE_CONFIGURE_ARGS} \
		if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		INSTALL="/usr/bin/install -c ${_BINOWNGRP}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; then \
			${ECHO_MSG} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
			(${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
			${FALSE}; \
		fi
.endfor

do-build:
.for i in . libiberty gold
	-cd ${WRKSRC}/${i} && \
		if ! ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}; then \
		if [ x != x${BUILD_FAIL_MESSAGE} ] ; then \
			${ECHO_MSG} "===> Compilation failed unexpectedly."; \
			(${ECHO_CMD} ${BUILD_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
			fi; \
		${FALSE}; \
		fi
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gold/ld-new ${PREFIX}/bin/

.include <bsd.port.post.mk>
