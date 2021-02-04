# $FreeBSD$

PORTNAME=	libsysctlmibinfo
DISTVERSION=	1.0.1
CATEGORIES=	devel

MAINTAINER=	alfix86@gmail.com
COMMENT=	Sysctl MIB-Tree API

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITLAB=	yes

GL_ACCOUNT=	alfix
GL_PROJECT=	sysctlmibinfo
GL_COMMIT=	941706f663a1fe17f2c1f5cfbf3c7211c8f41e53

USE_LDCONFIG=	yes

PLIST_FILES=	include/sysctlmibinfo.h \
		lib/libsysctlmibinfo.a \
		lib/libsysctlmibinfo.so \
		lib/libsysctlmibinfo.so.1.0.1 \
		man/man3/sysctlmibinfo.3.gz

do-install:
	${INSTALL_DATA} ${WRKSRC}/sysctlmibinfo.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libsysctlmibinfo.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libsysctlmibinfo.so.1.0.1 ${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/libsysctlmibinfo.so.1.0.1 ${STAGEDIR}${PREFIX}/lib/libsysctlmibinfo.so
	${INSTALL_MAN} ${WRKSRC}/sysctlmibinfo.3.gz ${STAGEDIR}${MAN3PREFIX}/man/man3

.include <bsd.port.mk>
