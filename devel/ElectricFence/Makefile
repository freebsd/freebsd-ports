PORTNAME=	electricfence
PORTVERSION=	2.2.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	PACKETSTORM/UNIX/misc
DISTNAME=	ElectricFence-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Debugging malloc() that uses the VM hardware to detect buffer overruns

USE_LDCONFIG=	yes
CFLAGS+=	-D__USE_BSD

MAKE_ARGS=	CC="${CC}"
PLIST_FILES=	bin/ef.sh lib/libefence.a lib/libefence.so.0 man/man3/efence.3.gz

do-install:
	${INSTALL_DATA} ${WRKSRC}/libefence.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libefence.so.0.0 ${STAGEDIR}${PREFIX}/lib/libefence.so.0
	${INSTALL_SCRIPT} ${WRKSRC}/ef.sh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/efence.3 ${STAGEDIR}${PREFIX}/man/man3

.include <bsd.port.mk>
