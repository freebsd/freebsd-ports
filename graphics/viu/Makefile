PORTNAME=	viu
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
PORTREVISION=	5
CATEGORIES=	graphics

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Simple terminal image viewer written in Rust
WWW=		https://github.com/atanunq/viu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	atanunq

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
