# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	premake
PORTVERSION=	3.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/Premake/${PORTVERSION}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Writes build scripts

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/Premake-${PORTVERSION}

USES=		gmake dos2unix

PLIST_FILES=	bin/premake

PORTDOCS=	CHANGES.txt LICENSE.txt README.txt

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/premake ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
