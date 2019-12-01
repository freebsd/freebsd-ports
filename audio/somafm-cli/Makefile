# $FreeBSD$

PORTNAME=	somafm-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
CATEGORIES=	audio

MAINTAINER=	vulcan@wired.sh
COMMENT=	Listen to SomaFM in your terminal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/README.md

RUN_DEPENDS=	bash:shells/bash \
		curl:ftp/curl \
		jq:textproc/jq \
		mpv:multimedia/mpv

USES=		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	rockymadden
SHEBANG_FILES=	src/somafm

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/somafm

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/somafm \
		${STAGEDIR}${PREFIX}/bin/somafm

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
