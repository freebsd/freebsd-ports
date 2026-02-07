PORTNAME=	openjdk11
PORTVERSION=	11.0.5.10.1
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	LOCAL/glewis/bootstrap-openjdk11 \
		LOCAL/pkubaj
PKGNAMEPREFIX=	bootstrap-
DISTNAME=	${JDK_PORT}-${JDK_ARCH}-${PORTVERSION}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java Development Kit 11
WWW=		https://openjdk.java.net/

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le

USES=		tar:xz

NO_BUILD=	yes
PLIST_SUB=	JDK_ROOT=${JDK_ROOT}
WRKSRC=		${WRKDIR}/${JDK_ROOT}

JDK_PORT=	${PKGNAMEPREFIX}${PORTNAME}
JDK_ROOT=	${PKGNAMEPREFIX}${PORTNAME}
JDK_ARCH=	${ARCH:C/armv.*/arm/}${JDK_ARCH_SUFFIX_${ARCH}}
JDK_ARCH_SUFFIX_powerpc64=	-elfv2

INSTALLDIR=	${STAGEDIR}${PREFIX}/${JDK_ROOT}

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64 || ${ARCH:Marmv*}
DISTNAME=	${JDK_PORT}-${JDK_ARCH}-12-${PORTVERSION}
PLIST_SUB+=	PPC=""
PLIST_SUB+=	PPC64LE=""
.elif ${ARCH} == powerpc64le
PLIST_SUB+=	PPC=""
PLIST_SUB+=	PPC64LE="@comment "
.elif ${ARCH} == powerpc
PLIST_SUB+=	PPC="@comment "
PLIST_SUB+=	PPC64LE=""
.else
PLIST_SUB+=	PPC=""
PLIST_SUB+=	PPC64LE=""
.endif

post-extract:
	-${MV} ${WRKSRC}/include/bsd ${WRKSRC}/include/freebsd

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${INSTALLDIR}
	@cd ${WRKSRC} && ${COPYTREE_BIN} bin ${INSTALLDIR}
	@${CHMOD} a+x ${INSTALLDIR}/lib/jspawnhelper

.include <bsd.port.post.mk>
