PORTNAME=	openjdk17
PORTVERSION=	17.0.1.12.1
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	LOCAL/glewis/bootstrap-openjdk17 \
		LOCAL/pkubaj/bootstrap-openjdk17
PKGNAMEPREFIX=	bootstrap-
DISTNAME=	${JDK_PORT}-${JDK_ARCH}-${PORTVERSION}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java Development Kit 17
WWW=		https://openjdk.java.net/

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc powerpc64 powerpc64le

USES=		tar:xz

NO_BUILD=	yes
PLIST_SUB=	JDK_ROOT=${JDK_ROOT}
WRKSRC=		${WRKDIR}/${JDK_ROOT}

JDK_PORT=	${PKGNAMEPREFIX}${PORTNAME}
JDK_ROOT=	${PKGNAMEPREFIX}${PORTNAME}
JDK_ARCH=	${ARCH:C/armv.*/arm/}

INSTALLDIR=	${STAGEDIR}${PREFIX}/${JDK_ROOT}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1500000
RUN_DEPENDS+=	compat14x-${ARCH}>=0:misc/compat14x
.endif

.if ${ARCH} == powerpc
PLIST_SUB+=	NOT_PPC="@comment "
.else
PLIST_SUB+=	NOT_PPC=""
.endif

.if ${ARCH:Mpowerpc64*}
PLIST_SUB+=	NOT_PPC64="@comment "
.else
PLIST_SUB+=	NOT_PPC64=""
.endif

.if ${ARCH} == i386
PLIST_SUB+=	NOT_I386="@comment "
.else
PLIST_SUB+=	NOT_I386=""
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${INSTALLDIR}
	@cd ${WRKSRC} && ${COPYTREE_BIN} bin ${INSTALLDIR}
	@${CHMOD} a+x ${INSTALLDIR}/lib/jspawnhelper

.include <bsd.port.mk>
