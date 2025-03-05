PORTNAME=	mvdsv
DISTVERSION=	1.11
PORTEPOCH=	2
CATEGORIES=	games
MASTER_SITES=	${WWW}/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}-source-with-submodules-${DISTVERSION}

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Enhanced QuakeWorld server with multi-view demos capability
WWW=		https://github.com/QW-Group/mvdsv

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre

USES=		cmake zip
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME} share/man/man6/${PORTNAME}.6.gz \
		${DATADIR_REL}/${PORTNAME}.png
PORTDOCS=	CODE_OF_CONDUCT.md README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/man/man6/${PORTNAME}.6 \
		${STAGEDIR}${PREFIX}/share/man/man6
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/resources/logo/${PORTNAME}.png \
		${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
