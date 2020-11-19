# $FreeBSD$

PORTNAME=	openjdk8
PORTVERSION=	${DISTVERSION_${JDK_ARCH}}
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	LOCAL/jkim \
		LOCAL/pkubaj
PKGNAMEPREFIX=	bootstrap-
DISTNAME=	${JDK_PORT}-${JDK_ARCH}-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Java Development Kit 8

LICENSE=	GPLv2

ONLY_FOR_ARCHS=		aarch64 amd64 armv6 armv7 i386 powerpc64 powerpc64le

DISTINFO_FILE=	${.CURDIR}/distinfo.${JDK_ARCH}
DISTVERSION_aarch64=	r453315
DISTVERSION_amd64=	r450802
DISTVERSION_arm=	r450802
DISTVERSION_i386=	r450802
DISTVERSION_ppc64=	r455236 # see below for ELFv2
DISTVERSION_ppc64le=	r555661

JDK_ARCH=	${ARCH:C/armv.*/arm/:S/powerpc/ppc/}
JDK_PORT=	openjdk8
JDK_ROOT=	bootstrap-${PORTNAME}

NO_BUILD=	yes
PLIST_SUB=	JDK_ARCH=${JDK_ARCH} JDK_ROOT=${JDK_ROOT}
USES=		tar:xz
WRKSRC=		${WRKDIR}/${JDK_ROOT}

INSTALLDIR=	${STAGEDIR}${PREFIX}/${JDK_ROOT}

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64 || ${ARCH:Marmv*}
RUN_DEPENDS+=	${LOCALBASE}/lib/compat/libffi.so.6:devel/libffi321
.endif

.if defined(PPC_ABI) && ${PPC_ABI} == ELFv2
DISTVERSION_ppc64=	r522831
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${INSTALLDIR}
	@cd ${WRKSRC} && ${COPYTREE_BIN} bin ${INSTALLDIR}

update:
	@${MAKE} -f ${.CURDIR}/Makefile.update \
	    JDK_PORT=${JDK_PORT} JDK_ROOT=${JDK_ROOT}

.include <bsd.port.post.mk>
