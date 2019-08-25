# $FreeBSD$

PORTNAME=	openjdk11
PORTVERSION=	11.0.2.9.2
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	LOCAL/glewis/bootstrap-openjdk11
PKGNAMEPREFIX=	bootstrap-
DISTNAME=	${JDK_PORT}-${JDK_ARCH}-${PORTVERSION}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java Development Kit 11

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386 powerpc64

USES=		tar:xz

NO_BUILD=	yes
PLIST_SUB=	JDK_ROOT=${JDK_ROOT}
WRKSRC=		${WRKDIR}/${JDK_ROOT}

JDK_PORT=	${PKGNAMEPREFIX}${PORTNAME}
JDK_ROOT=	${PKGNAMEPREFIX}${PORTNAME}
JDK_ARCH=	${ARCH}

INSTALLDIR=	${STAGEDIR}${PREFIX}/${JDK_ROOT}

post-extract:
	-${MV} ${WRKSRC}/include/bsd ${WRKSRC}/include/freebsd

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${INSTALLDIR}
	@cd ${WRKSRC} && ${COPYTREE_BIN} bin ${INSTALLDIR}
	@${CHMOD} a+x ${INSTALLDIR}/lib/jspawnhelper

.include <bsd.port.mk>
