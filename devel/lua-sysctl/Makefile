# $FreeBSD$

PORTNAME=	sysctl
PORTVERSION=	2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Small sysctl(3) interface for lua

LICENSE=	BSD2CLAUSE

BROKEN_FreeBSD_10=	does not build (error: use of undeclared identifier 'CTLTYPE_S8')

USES=		pkgconfig lua

USE_GITHUB=	yes
GH_ACCOUNT=	kAworu
GH_PROJECT=	lua-${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s/5.1/${LUA_VER}/g" ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR} \
		${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${DOCSDIR}/${PKGNAMEPREFIX}${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/misc/*.lua ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/${PKGNAMEPREFIX}${PORTNAME}
	${INSTALL_LIB} ${WRKSRC}/build/sysctl.so ${STAGEDIR}${LUA_MODLIBDIR}/sysctl.so

.include <bsd.port.mk>
