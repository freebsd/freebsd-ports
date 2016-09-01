# $FreeBSD$

PORTNAME=	neo4j
DISTVERSION=	3.0.4
CATEGORIES=	databases java
MASTER_SITES=	http://dist.neo4j.org/
DISTNAME=	${PORTNAME}-community-${DISTVERSION}-unix

MAINTAINER=	crees@FreeBSD.org
COMMENT=	High performance graph store and database

RUN_DEPENDS=	bash:shells/bash

WRKSRC=		${WRKDIR}/${DISTNAME:S,-unix,,}
NO_BUILD=	yes
USE_JAVA=	yes
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	${PORTNAME}.sh

post-patch:
	${REINPLACE_CMD} 's,%%DATADIR%%,${DATADIR},g;s,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/bin/neo4j-shared.sh ${WRKSRC}/conf/neo4j.conf

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/tools
	${INSTALL_SCRIPT} ${WRKSRC}/bin/tools/* \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/tools
.for j in j j-admin j-import j-shell
	${INSTALL_SCRIPT} ${WRKSRC}/bin/neo4$j ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	-cd ${STAGEDIR}${PREFIX}/bin && ${LN} ${PORTNAME} neo4$j 2>/dev/null
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/lib/* ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME}-shared.sh \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
.for f in ${PORTNAME}.conf ${PORTNAME}-wrapper.conf
	${INSTALL_DATA} ${WRKSRC}/conf/$f \
		${STAGEDIR}${PREFIX}/etc/$f.sample
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${PREFIX}/etc/neo4j-certificates
.include <bsd.port.mk>
