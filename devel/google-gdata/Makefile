# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-gdata
PORTVERSION=	1.4.0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}:1 \
		http://www.zlib.net/:2
DISTNAME=	libgoogle-data-mono-${PORTVERSION}
DISTFILES=	libgoogle-data-mono-${PORTVERSION}${EXTRACT_SUFX}:1 zlib-${ZLIBVER}${EXTRACT_SUFX}:2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	.NET library for the Google Data API

BUILD_DEPENDS=	gmcs:${PORTSDIR}/lang/mono

USES=		dos2unix gmake
DOS2UNIX_FILES=	Makefile misc/gdata-sharp-core.pc.in

# google-gdata depends on _THIS_ version of zlib so make them happy.
ZLIBVER=	1.2.3

# Google GData Client library directory
GGCDIR=		lib/mono/gac/Google.GData.Client/1.4.0.2__04a59ca9b0273830
PLIST_SUB=	GGCDIR=${GGCDIR}

pre-configure:
	@${ECHO_CMD} "--->  Configuring for zlib-${ZLIBVER}"
	(cd ${WRKDIR}/zlib-${ZLIBVER} && \
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
	@${ECHO_CMD} "--->  Building for zlib-${ZLIBVER}"
	(cd ${WRKDIR}/zlib-${ZLIBVER} && ${MAKE_CMD})
	@${ECHO_CMD} "--->  Returning to build for ${PKGNAME}"

post-install:
	${INSTALL_LIB} ${WRKDIR}/zlib-${ZLIBVER}/libz.so.${ZLIBVER} \
		${STAGEDIR}${PREFIX}/${GGCDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/Google.GData.Client.dll.config \
		${STAGEDIR}${PREFIX}/${GGCDIR}

.include <bsd.port.mk>
