# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ahven
PORTVERSION=	2.6
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://www.ahven-framework.com/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ada unit test framework

LICENSE=	ISCL

BUILD_DEPENDS=	adactl:lang/adacontrol

USES=		ada gmake
MAKE_ENV=	OS_VERSION=unix

OPTIONS_DEFINE=		TRACE
OPTIONS_DEFAULT=	TRACE
NO_OPTIONS_SORT=	yes
TRACE_DESC=		Build with GNAT-specific symbolic tracing functionality

TRACE_EXTRA_PATCHES=	${FILESDIR}/extra-src_ahven-framework.adb

do-build:
	(cd ${WRKSRC} && ${MKDIR} lib objects)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -Pgnat/ahven_lib)

do-install:
	(cd ${STAGEDIR}${PREFIX} && ${MKDIR} lib/gnat lib/ahven include/ahven)
	${INSTALL_DATA} ${WRKSRC}/src/*.ad[bs] \
		${STAGEDIR}${PREFIX}/include/ahven
	${INSTALL_DATA} ${WRKSRC}/lib/*.ali ${STAGEDIR}${PREFIX}/lib/ahven
	${INSTALL_DATA} ${WRKSRC}/lib/libahven.a ${STAGEDIR}${PREFIX}/lib/ahven
	${INSTALL_DATA} ${FILESDIR}/ahven.gpr ${STAGEDIR}${PREFIX}/lib/gnat

.include <bsd.port.mk>
