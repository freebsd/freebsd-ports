# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	fujaba
PORTVERSION=	4.3.2
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	http://wwwcs.uni-paderborn.de/cs/fujaba/downloads/packages/Fujaba_4/
DISTNAME=	FujabaToolSuite_Developer${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another UML CASE tool

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Fujaba\ Tool\ Suite\ ${PORTVERSION}

DATADIRS=	DTDs Templates libs plugins stylesheets
DATAFILES=	GNULesserGeneralPublicLicense.txt api.zip fujaba.jar src.jar

PLIST_FILES=	bin/fujaba
PORTDATA=	*
PORTDOCS=	*

SUB_FILES=	fujaba.sh
SUB_LIST=	LOCALBASE="${LOCALBASE}" DATADIR="${DATADIR}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/fujaba.sh ${STAGEDIR}${DATADIR}/bin
	${LN} -s ${DATADIR}/bin/fujaba.sh ${STAGEDIR}${PREFIX}/bin/fujaba
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${DATADIRS}" ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DATAFILES} ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.if ${PORT_OPTIONS:MDOCS}
	${LN} -s ${DOCSDIR} ${STAGEDIR}${DATADIR}/doc
.endif

.include <bsd.port.mk>
