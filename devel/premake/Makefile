# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	premake
PORTVERSION=	3.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/Premake/${PORTVERSION}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Build script creation tool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

WRKSRC=		${WRKDIR}/Premake-${PORTVERSION}

USES=		dos2unix gmake zip

PLIST_FILES=	bin/premake

PORTDOCS=	CHANGES.txt README.txt

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/premake ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
