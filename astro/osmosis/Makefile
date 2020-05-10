# Created by: Gleb Smirnoff <glebius@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osmosis
PORTVERSION=	0.48.0
CATEGORIES=	astro java
MASTER_SITES=	https://github.com/openstreetmap/osmosis/releases/download/${PORTVERSION}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Command line Java app for processing OpenStreetMap data

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/copying.txt

USES=		tar:tgz
USE_JAVA=	yes
NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|^\(MYAPP_HOME=\).*|\1${DATADIR}|' ${WRKSRC}/bin/osmosis

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "script config lib" ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/osmosis ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/changes.txt ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

do-test:
	${JAVA} \
		-cp ${STAGEDIR}${DATADIR}/lib/default/plexus-classworlds-*.jar \
		-Dapp.home=${STAGEDIR}${DATADIR} \
		-Dclassworlds.conf=${STAGEDIR}${DATADIR}/config/plexus.conf \
		org.codehaus.classworlds.Launcher

.include <bsd.port.mk>
