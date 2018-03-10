# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pragmarcs
PORTVERSION=	20161207
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PragmAda Reusable Components

LICENSE=	GPLv2 GMGPL
LICENSE_COMB=	multi

USES=		ada
USE_GITHUB=	yes
GH_ACCOUNT=	jrcarter
GH_PROJECT=	PragmARC
GH_TAGNAME=	1378e7a

post-extract:
	@${CP} ${FILESDIR}/buildlib.gpr ${WRKSRC}/
	${RM} ${WRKSRC}/compile_all.adb

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -p -Pbuildlib)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/pragmarcs \
		${STAGEDIR}${PREFIX}/lib/pragmarcs \
		${STAGEDIR}${PREFIX}/lib/gnat
	${INSTALL_DATA} ${WRKSRC}/library/* ${STAGEDIR}${PREFIX}/lib/pragmarcs
	${INSTALL_DATA} ${WRKSRC}/*.ad[bs] \
		${STAGEDIR}${PREFIX}/include/pragmarcs
	${INSTALL_DATA} ${FILESDIR}/pragmarcs.gpr ${STAGEDIR}${PREFIX}/lib/gnat

.include <bsd.port.mk>
