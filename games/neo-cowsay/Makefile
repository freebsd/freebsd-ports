PORTNAME=	neo-cowsay
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Neo Cowsay written in Go

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/Code-Hex/Neo-cowsay/v2

GO_TARGET=	./cmd/cowsay:neo-cowsay ./cmd/cowthink:neo-cowthink

PLIST_FILES=	bin/neo-cowsay \
		bin/neo-cowthink

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install:
.for l in neo-cowsay neo-cowthink
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${l}
.endfor

.include <bsd.port.mk>
