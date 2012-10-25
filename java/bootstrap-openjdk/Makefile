# $FreeBSD$

PORTNAME=	${JDK_NAME}
PORTVERSION=	${DISTVERSION_${ARCH}}
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkim
PKGNAMEPREFIX=	bootstrap-
DISTNAME=	${JDK_PORT}-${ARCH}-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Oracle's Java 6 virtual machine release under the GPL v2

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/registervm:${PORTSDIR}/java/javavmwrapper
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/share/java/zi:${PORTSDIR}/java/java-zoneinfo

ONLY_FOR_ARCH=	amd64 i386

DISTINFO_FILE=	${.CURDIR}/distinfo.${ARCH}
DISTVERSION_amd64=	r306294
DISTVERSION_i386=	r306294

JDK_NAME=	openjdk
JDK_PORT=	openjdk6
JDK_ROOT=	bootstrap-${JDK_NAME}

NO_BUILD=	yes
PLIST_SUB=	ARCH=${ARCH} JDK_NAME=${JDK_NAME} JDK_ROOT=${JDK_ROOT}
USE_XZ=		yes
WRKSRC=		${WRKDIR}/${JDK_ROOT}

INSTALLDIR=	${PREFIX}/${JDK_ROOT}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800105
RUN_DEPENDS+=	${LOCALBASE}/lib/compat/libz.so.4:${PORTSDIR}/misc/compat7x
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	CLIENTVM=""
.else
PLIST_SUB+=	CLIENTVM="@comment "
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${INSTALLDIR}
	@${CHOWN} ${BINOWN}:${BINGRP} ${INSTALLDIR}/bin/*
	@${CHMOD} ${BINMODE} ${INSTALLDIR}/bin/*
	@${ECHO_CMD} "@exec ${LOCALBASE}/bin/registervm '${INSTALLDIR}/bin/java # Bootstrap JDK'" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${LOCALBASE}/bin/unregistervm ${INSTALLDIR}/bin/java" >> ${TMPPLIST}

post-install:
	@${LOCALBASE}/bin/registervm '${INSTALLDIR}/bin/java # Bootstrap JDK'
	@${CAT} ${PKGMESSAGE}

update:
	@${MAKE} -f ${.CURDIR}/Makefile.update \
	    JDK_NAME=${JDK_NAME} JDK_PORT=${JDK_PORT} JDK_ROOT=${JDK_ROOT}

.include <bsd.port.post.mk>
