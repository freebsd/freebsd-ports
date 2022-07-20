PORTNAME=	fhourstones
PORTVERSION=	3.1
PORTREVISION=	2
CATEGORIES=	benchmarks
MASTER_SITES=	http://tromp.github.io/c4/
DISTNAME=	Fhourstones

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Integrated benchmark program

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/fhourstones \
		libexec/fhourstones/SearchGame \
		share/fhourstones/inputs

post-patch:
	@${REINPLACE_CMD} -e \
		's| = -O3| +=|' ${WRKSRC}/Makefile

post-build:
	${ECHO_CMD} '#!${SH}' > ${WRKSRC}/fhourstones
	${ECHO_CMD} 'libexecdir=${PREFIX}/libexec/fhourstones' \
		>> ${WRKSRC}/fhourstones
	${ECHO_CMD} 'datadir=${DATADIR}' >> ${WRKSRC}/fhourstones
	${ECHO_CMD} 'exec $${libexecdir}/SearchGame < $${datadir}/inputs' \
		>> ${WRKSRC}/fhourstones

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/fhourstones ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT}  ${WRKSRC}/fhourstones ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA}    ${WRKSRC}/inputs ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/SearchGame \
		${STAGEDIR}${PREFIX}/libexec/fhourstones

.include <bsd.port.mk>
