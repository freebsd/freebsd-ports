PORTNAME=	safe-iop
DISTVERSION=	0.3.2
CATEGORIES=	devel

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Safe integer operation library for C

# as defined in /usr/src/include/ifaddrs.h
LICENSE=	BSD1CLAUSE
LICENSE_NAME=	BSD1CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_LDCONFIG=	yes
ALL_TARGET=	so
CFLAGS+=	-fPIC

PLIST_FILES=	include/safe_iop.h \
		lib/libsafe_iop.so.0 \
		%%DOCSDIR%%/README \
		%%DOCSDIR%%/README.md \
		%%EXAMPLESDIR%%/askme.c

USE_GITLAB=	yes
GL_ACCOUNT=	ports1
GL_PROJECT=	safe-iop
GL_COMMIT=	2b20d77fb9f22b1ec9e2b3d2eb53c532596d3203

do-install:
	${INSTALL_LIB} ${WRKSRC}/libsafe_iop.so.0 ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/safe_iop.h ${STAGEDIR}${PREFIX}/include
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/askme.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
