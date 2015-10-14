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

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/Premake-${PORTVERSION}

USES=		gmake dos2unix zip

PLIST_FILES=	bin/premake

PORTDOCS=	CHANGES.txt LICENSE.txt README.txt

MAKE_JOBS_UNSAFE=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/premake ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
