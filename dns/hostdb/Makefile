# Created by: rodrigc@FreeBSD.org
# $FreeBSD$

PORTNAME=	hostdb
PORTVERSION=	1.004
CATEGORIES=	dns
MASTER_SITES=	GOOGLE_CODE
EXTRACT_SUFX=	.tgz

MAINTAINER=	rodrigc@FreeBSD.org
COMMENT=	Generate DNS and DHCP config files from single source

NO_BUILD=	yes

HOSTDB_EXAMPLES_DIRS=	example1/out example1/ example2 hiddenmaster
HOSTDB_EXAMPLES_DIRS+=	mailserverexample/out mailserverexample

.include <bsd.port.options.mk>

pre-install:
	${FIND} ${WRKSRC} -name "*\.orig" -delete

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${PREFIX}/bin
.if ${PORT_OPTIONS:MEXAMPLES}
.for dir in ${HOSTDB_EXAMPLES_DIRS}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/
.endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
.endif

.include <bsd.port.mk>
