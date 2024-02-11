PORTNAME=	premake
PORTVERSION=	3.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/Premake/${PORTVERSION}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Build script creation tool
WWW=		http://premake.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Legacy unsupported version, consider devel/premake4 or devel/premake5
EXPIRATION_DATE=2024-03-31

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
