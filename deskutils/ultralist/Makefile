PORTNAME=	ultralist
DISTVERSION=	1.7.0
PORTREVISION=	28
CATEGORIES=	deskutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Simple, powerful, task management system for the command line
WWW=		https://ultralist.io

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules
USE_GITHUB=	yes
GH_TUPLE=	golang:sys:v0.5.0:golang_sys/vendor/golang.org/x/sys_

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-extract:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${MV} ${WRKSRC}/vendor/golang.org/x/sys_ ${WRKSRC}/vendor/golang.org/x/sys

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
