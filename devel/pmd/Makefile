PORTNAME=	pmd
DISTVERSION=	7.16.0
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTNAME}_releases/${DISTVERSION}/
DISTNAME=	${PORTNAME}-dist-${DISTVERSION}-bin

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	Static analysis tool for Java source code
WWW=		https://pmd.github.io/

LICENSE=	APACHE20 BSD4CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe java zip
CPE_VENDOR=	pmd_project

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-bin-${DISTVERSION}
PLIST_SUB+=	ETCDIR=${ETCDIR} \
		PORTVERSION=${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' -e 's|%%ETCDIR%%|${ETCDIR}|g' \
		${WRKSRC}/bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/simplelogger.properties \
		${STAGEDIR}${ETCDIR}/simplelogger.properties.sample
	cd ${WRKSRC} && ${COPYTREE_SHARE} sbom ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
