PORTNAME=	asmx
PORTVERSION=	2.0.0
CATEGORIES=	devel
MASTER_SITES=	http://xi6.com/files/

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	Multi-CPU macro assembler for many major 8-bit and 16-bit CPUs
WWW=		http://xi6.com/projects/asmx/

LICENSE=	PD

USES=		zip
NO_WRKSUBDIR=	yes

do-build:
	cd ${BUILD_WRKSRC}/src && ${CC} ${CFLAGS} *.c -o asmx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/asmx ${STAGEDIR}${PREFIX}/bin
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/asmx
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/asmx-doc.html ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${BUILD_WRKSRC}/test && ${SHELL} testit

.include <bsd.port.mk>
