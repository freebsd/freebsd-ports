# Ports collection makefile for:	ace
# Date created:				5 January 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	ace
PORTVERSION=	5.5.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	ftp://download.dre.vanderbilt.edu/previous_versions/ \
		http://download.dre.vanderbilt.edu/previous_versions/
DISTNAME=	ACE-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Adaptive Communication Environment for C++

CONFLICTS=	ace+tao-5*

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--program-transform-name s,^,ace-,
USE_GNOME=	gnometarget pkgconfig

WRKSRC=		${WRKDIR}/ACE_wrappers
BUILD_WRKSRC=	${WRKSRC}/objdir
INSTALL_WRKSRC=	${BUILD_WRKSRC}
NOT_FOR_ARCHS=	sparc64
MAKE_JOBS_SAFE=	yes

MAN1=		ace-gperf.1

.include <bsd.port.pre.mk>

.if (${OSVERSION} >= 601103 && ${OSVERSION} < 700000) || ${OSVERSION} >= 700015
EXTRA_PATCHES+=	${FILESDIR}/extra-ace-OS_NS_netdb.inl
.endif

.if ${OSVERSION} >= 700110 && ${OSVERSION} < 800000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-ace-OS_NS_Thread.h
.endif

post-extract:
	@${MKDIR} ${BUILD_WRKSRC}

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@libdir@/pkgconfig|@prefix@/libdata/pkgconfig|g'
.if (${OSVERSION} >= 700110 && ${OSVERSION} < 800000) || ${OSVERSION} >= 800024
	@${REINPLACE_CMD} -e 's|cpu_set_t|cpuset_t|g' ${WRKSRC}/ace/OS_NS_Thread.cpp \
		${WRKSRC}/ace/OS_NS_Thread.h
.endif

do-configure:
	@(cd ${BUILD_WRKSRC} && \
		if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    INSTALL="/usr/bin/install -c ${_BINOWNGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ../${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; then \
			 ${ECHO_CMD} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
			 (${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
			 ${FALSE}; \
		fi)

post-install:
	@for f in `${GREP} "${PORTVERSION}.*\.so$$" ${PLIST}`; do \
		n=`echo $${f}|sed -e 's/-${PORTVERSION}//'`; \
		${LN} -fs ${PREFIX}/$$f ${PREFIX}/$${n}.5; \
	done

.include <bsd.port.post.mk>
