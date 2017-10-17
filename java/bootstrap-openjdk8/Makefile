# $FreeBSD$

PORTNAME=	openjdk8
PORTVERSION=	${DISTVERSION_${JDK_ARCH}}
CATEGORIES=	java devel
MASTER_SITES=	LOCAL/jkim
PKGNAMEPREFIX=	bootstrap-
DISTNAME=	${JDK_PORT}-${JDK_ARCH}-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Java Development Kit 8

LICENSE=	GPLv2

ONLY_FOR_ARCHS=		amd64 armv6 armv7 i386

DISTINFO_FILE=	${.CURDIR}/distinfo.${JDK_ARCH}
DISTVERSION_amd64=	r450802
DISTVERSION_arm=	r450802
DISTVERSION_i386=	r450802

JDK_ARCH=	${ARCH:C/armv.*/arm/}
JDK_PORT=	openjdk8
JDK_ROOT=	bootstrap-${PORTNAME}

NO_BUILD=	yes
PLIST_SUB=	JDK_ARCH=${JDK_ARCH} JDK_ROOT=${JDK_ROOT}
USES=		tar:xz
WRKSRC=		${WRKDIR}/${JDK_ROOT}

INSTALLDIR=	${STAGEDIR}${PREFIX}/${JDK_ROOT}

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv*}
RUN_DEPENDS+=	${LOCALBASE}/lib/libffi.so.6:devel/libffi
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${INSTALLDIR}
	@cd ${WRKSRC} && ${COPYTREE_BIN} bin ${INSTALLDIR}

update:
	@${MAKE} -f ${.CURDIR}/Makefile.update \
	    JDK_PORT=${JDK_PORT} JDK_ROOT=${JDK_ROOT}

.include <bsd.port.post.mk>
