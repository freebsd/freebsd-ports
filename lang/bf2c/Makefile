# Created by: rene

PORTNAME=	bf2c
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optimizing BrainF*ck to C compiler

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	No development since 2013
EXPIRATION_DATE=2022-02-28

PATCH_STRIP=	-p1
USE_GITHUB=	yes
GH_ACCOUNT=	rene0

OPTIONS_DEFINE=	DOCS

INSTALL_TARGET=	install-strip

PORTDOCS=	README.md

PLIST_FILES=	bin/bf2c bin/gen_bf

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
