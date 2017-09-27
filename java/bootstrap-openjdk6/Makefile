# $FreeBSD$

PORTNAME=	openjdk6
PORTVERSION=	${DISTVERSION_${ARCH}}
CATEGORIES=	java devel
MASTER_SITES=	LOCAL/jkim
PKGNAMEPREFIX=	bootstrap-
DISTNAME=	${PORTNAME}-${ARCH}-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Oracle\'s Java 6 virtual machine release under the GPL v2

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386

RUN_DEPENDS=	java-zoneinfo>0:java/java-zoneinfo \
		${LOCALBASE}/lib/libfreetype.so.6:print/freetype2

DISTINFO_FILE=	${.CURDIR}/distinfo.${ARCH}
DISTVERSION_amd64=	r450701
DISTVERSION_i386=	r450701

JDK_ROOT=	bootstrap-${PORTNAME}

NO_BUILD=	yes
PLIST_SUB=	ARCH=${ARCH} JDK_ROOT=${JDK_ROOT}
USES=		tar:xz
WRKSRC=		${WRKDIR}/${JDK_ROOT}

INSTALLDIR=	${STAGEDIR}${PREFIX}/${JDK_ROOT}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
PLIST_SUB+=	CLIENTVM=""
.else
PLIST_SUB+=	CLIENTVM="@comment "
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${INSTALLDIR}
	@cd ${WRKSRC} && ${COPYTREE_BIN} "bin jre/bin" ${INSTALLDIR}

update:
	@${MAKE} -f ${.CURDIR}/Makefile.update \
	    JDK_PORT=${PORTNAME} JDK_ROOT=${JDK_ROOT}

.include <bsd.port.post.mk>
