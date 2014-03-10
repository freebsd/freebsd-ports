# Created by: Pedro Giffuni
# $FreeBSD$

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

NO_STAGE=	yes
.include <bsd.port.pre.mk>

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
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/NetRexxC.sh ${PREFIX}/bin
	@${LN} -sf ${PREFIX}/bin/NetRexxC.sh ${PREFIX}/bin/nrc

	@${INSTALL_DATA} ${WRKSRC}/lib/NetRexxC.jar ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/runlib/NetRexxR.jar ${JAVAJARDIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/bin/hello.nrx \
		${EXAMPLESDIR}
	@cd ${WRKSRC}/browse && \
		${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	@cd ${WRKSRC}/browse && \
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

post-install:
	@${ECHO} "====================  IBM LICENSE  ===================="
	@${CAT} ${WRKSRC}/browse/license.txt
	@${ECHO} "-------------------------------------------------------"
	@${ECHO} "====================  IMPORTANT!!  ===================="
	@${CAT} ${WRKSRC}/read.me.first

.include <bsd.port.post.mk>
