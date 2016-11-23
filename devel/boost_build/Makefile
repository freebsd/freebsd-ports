# Created by: Bruce M. Simpson
# $FreeBSD$

PORTNAME=	boost_build
PORTVERSION=	2.0.m12
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/boost/boost-build/2.0-m12
DISTNAME=	${PORTNAME:S/_/-/g}-${PORTVERSION:S/.m/-m/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible cross-platform build tool suite

LICENSE=	BSL

RUN_DEPENDS=	${LOCALBASE}/bin/bjam:devel/boost-jam

USES=		tar:bzip2
WRKSRC=		${WRKDIR}/${PORTNAME:S/_/-/g}
NO_BUILD=	defined

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_FILES=	share/doc/boost.png
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "build kernel options tools util" \
		${STAGEDIR}${DATADIR} "! -name *.orig")
	(cd ${WRKSRC} && ${INSTALL_DATA} boost-build.jam bootstrap.jam \
		build-system.jam site-config.jam user-config.jam \
		${STAGEDIR}${DATADIR})
	${INSTALL_MAN} ${WRKSRC}/boost.png \
		${STAGEDIR}${PREFIX}/share/doc/boost.png
	(cd ${WRKSRC}/doc && ${RM} -r Jamfile.v2 project-root.jam \
		html/userman_HTML.manifest src)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} .  ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
