# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-gdata
PORTVERSION=	1.4.0.2
CATEGORIES=	devel
MASTER_SITES=	http://google-gdata.googlecode.com/files/:1 \
    		http://www.zlib.net/:2
DISTNAME=	libgoogle-data-mono-${PORTVERSION}
DISTFILES=	libgoogle-data-mono-${PORTVERSION}${EXTRACT_SUFX}:1 zlib-${ZLIB_VERSION}${EXTRACT_SUFX}:2

MAINTAINER=	mono@FreeBSD.org
COMMENT=	.NET library for the Google Data API

BUILD_DEPENDS=	gmcs:${PORTSDIR}/lang/mono

# google-gdata depends on _THIS_ version of zlib so make them happy.
ZLIB_VERSION=	1.2.3

USE_GMAKE=	yes

NO_STAGE=	yes
pre-configure:
	@${ECHO_CMD} "--->  Configuring for zlib-${ZLIB_VERSION}"
	@(cd ${WRKDIR}/zlib-${ZLIB_VERSION} && \
	    ${SET_LATE_CONFIGURE_ARGS} \
	    if ! ${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    INSTALL="/usr/bin/install -c ${_BINOWNGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_LIB="${INSTALL_LIB}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} --shared; then \
		 ${ECHO_MSG} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
		 (${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
		 ${FALSE}; \
	    fi)

pre-build:
	@${ECHO_CMD} "--->  Building for zlib-${ZLIB_VERSION}"
	@cd ${WRKDIR}/zlib-${ZLIB_VERSION} && ${MAKE}
	@${ECHO_CMD} "--->  Returning to build for ${PKGNAME}"

post-install:
	@${CP} ${WRKDIR}/zlib-${ZLIB_VERSION}/libz.so.${ZLIB_VERSION} \
	    ${WRKSRC}/misc/Google.GData.Client.dll.config \
	    ${PREFIX}/lib/mono/gac/Google.GData.Client/${PORTVERSION}__04a59ca9b0273830/

.include <bsd.port.mk>
