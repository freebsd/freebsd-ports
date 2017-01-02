# $FreeBSD$

PORTNAME=	${JDK_NAME}
PORTVERSION=	${DISTVERSION_${JDK_ARCH}}
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	${JDK_MASTER_SITES}
PKGNAMEPREFIX=	bootstrap-
DISTNAME=	${JDK_PORT}-${JDK_ARCH}-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Oracle\'s Java 6 virtual machine release under the GPL v2

LICENSE=	GPLv2

RUN_DEPENDS=	java-zoneinfo>0:java/java-zoneinfo
BUNDLE_LIBS=	yes

ONLY_FOR_ARCHS=	amd64 armv6 armv6hf i386 powerpc64

DISTINFO_FILE=	${.CURDIR}/distinfo.${JDK_ARCH}
DISTVERSION_amd64=	r351880
DISTVERSION_arm=	r378760
DISTVERSION_i386=	r351880
DISTVERSION_powerpc64=	r407937

JDK_ARCH=	${ARCH:C/armv6.*/arm/}
JDK_NAME=	openjdk
JDK_ROOT=	bootstrap-${JDK_NAME}

NO_BUILD=	yes
PLIST_SUB=	JDK_ARCH=${JDK_ARCH} JDK_NAME=${JDK_NAME} JDK_ROOT=${JDK_ROOT}
USES=		tar:xz
WRKSRC=		${WRKDIR}/${JDK_ROOT}

INSTALLDIR=	${STAGEDIR}${PREFIX}/${JDK_ROOT}

.if !exists(/usr/lib/libstdc++.so.6)
PLIST_SUB+=	LIBSTDCXX=""
.else
EXCLUDE_EXP=	-not -name libstdc++.so.6
PLIST_SUB+=	LIBSTDCXX="@comment "
.endif

.include <bsd.port.pre.mk>

JDK_MASTER_SITES=	LOCAL/jkim

.if ${ARCH:Marmv6*}
JDK_PORT=	openjdk7
.else
JDK_PORT=	openjdk6
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	CLIENTVM=""
.else
PLIST_SUB+=	CLIENTVM="@comment "
.endif

.if ${ARCH} == "powerpc64"
JDK_PORT=	openjdk7
JDK_NAME=	openjdk
JDK_MASTER_SITES=	LOCAL/glewis/bootstrap-openjdk
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${INSTALLDIR} "${EXCLUDE_EXP}"
	@cd ${WRKSRC} && ${COPYTREE_BIN} "bin jre/bin" ${INSTALLDIR}

update:
	@${MAKE} -f ${.CURDIR}/Makefile.update \
	    JDK_NAME=${JDK_NAME} JDK_PORT=${JDK_PORT} JDK_ROOT=${JDK_ROOT}

.include <bsd.port.post.mk>
