PORTNAME=	NetRexx
PORTVERSION=	2.05
PORTREVISION=	3
CATEGORIES=	java lang
MASTER_SITES=	ftp://ftp.software.ibm.com/software/awdtools/netrexx/
DISTNAME=	NetRexx

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Human-oriented programming language for writing/using Java classes

NO_BUILD=	yes
USES=		zip
USE_JAVA=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-patch:
	for file in ${WRKSRC}/bin/NetRexxC.sh ${WRKSRC}/read.me.first; do \
	    ${TR} -d '\015' < $${file} > $${file}.new; \
	    ${MV} $${file}.new $${file}; \
	done

post-patch:
	${REINPLACE_CMD} -e 's,%%JAVA_HOME%%,${JAVA_HOME},' \
	                 -e 's,%%JAVAJARDIR%%,${JAVAJARDIR},' \
	                 ${WRKSRC}/bin/NetRexxC.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/NetRexxC.sh ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/NetRexxC.sh ${STAGEDIR}${PREFIX}/bin/nrc
	${INSTALL_DATA} ${WRKSRC}/lib/NetRexxC.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/runlib/NetRexxR.jar ${STAGEDIR}${JAVAJARDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/hello.nrx ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/browse && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

	@${ECHO} "====================  IBM LICENSE  ===================="
	@${CAT} ${WRKSRC}/browse/license.txt
	@${ECHO} "-------------------------------------------------------"
	@${ECHO} "====================  IMPORTANT!!  ===================="
	@${CAT} ${WRKSRC}/read.me.first

.include <bsd.port.mk>
