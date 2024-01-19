PORTNAME=	libsysctlmibinfo
DISTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	alfix86@gmail.com
COMMENT=	Sysctl MIB-Tree API
WWW=		https://gitlab.com/alfix/sysctlmibinfo/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITLAB=	yes

GL_ACCOUNT=	alfix
GL_PROJECT=	sysctlmibinfo
GL_TAGNAME=	d09fc0361b258059a6781afa6fd0a58e332f3a74

USE_LDCONFIG=	yes

PLIST_FILES=	include/sysctlmibinfo.h \
		lib/libsysctlmibinfo.a \
		lib/libsysctlmibinfo.so \
		lib/libsysctlmibinfo.so.1.0.2 \
		share/man/man3/sysctlmibinfo.3.gz

do-install:
	${INSTALL_DATA} ${WRKSRC}/sysctlmibinfo.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libsysctlmibinfo.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libsysctlmibinfo.so.1.0.2 ${STAGEDIR}${PREFIX}/lib
	${RLN} ${STAGEDIR}${PREFIX}/lib/libsysctlmibinfo.so.1.0.2 ${STAGEDIR}${PREFIX}/lib/libsysctlmibinfo.so
	${INSTALL_MAN} ${WRKSRC}/sysctlmibinfo.3.gz ${STAGEDIR}${PREFIX}/share/man/man3

.include <bsd.port.mk>
