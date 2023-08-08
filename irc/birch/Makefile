PORTNAME=	birch
DISTVERSION=	g20200327
CATEGORIES=	irc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	IRC client written in bash
WWW=		https://github.com/dylanaraps/birch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	dylanaraps
GH_TAGNAME=	f04f673a57d3f416174fb84755d528aefe5adc6d
SHEBANG_FILES=	${PORTNAME}

DEPRECATED=	Upstream no longer maintained
EXPIRATION_DATE=	2023-08-25

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
