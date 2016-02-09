# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	nini
PORTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	SF/nini/Nini/${PORTVERSION}
DISTNAME=	Nini-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NET configuration library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		mono zip
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/Nini
NINI_VERSION=	${PORTVERSION:C/([0-9]*\.[0-9]*).*/\1/}
SUB_FILES=	${PORTNAME}.pc
SUB_LIST=	PORTVERSION=${PORTVERSION} \
		NINI_VERSION=${NINI_VERSION}
PLIST_SUB=	NINI_VERSION=${NINI_VERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@(cd ${INSTALL_WRKSRC}/Bin/Mono/1.1/Release && ${SETENV} MONO_SHARED_DIR=${WRKDIR} ${LOCALBASE}/bin/gacutil -root ${STAGEDIR}${PREFIX}/lib/ -gacdir ${STAGEDIR}${PREFIX}/lib -package ${PORTNAME}-${NINI_VERSION} -i Nini.dll)
	${INSTALL_DATA} ${WRKDIR}/nini.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/nini-${NINI_VERSION}.pc

do-install-DOCS-on:
	@(cd ${WRKSRC}/Docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	@(cd ${WRKSRC}/Examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
