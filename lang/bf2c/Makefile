# Created by: rene
# $FreeBSD$

PORTNAME=	bf2c
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Optimizing BrainF*ck to C compiler

LICENSE=	BSD2CLAUSE

USES=		tar:xz

PATCH_STRIP=	-p1
USE_GITHUB=	yes
GH_ACCOUNT=	rene0
GH_COMMIT=	4761081

OPTIONS_DEFINE=	DOCS

INSTALL_TARGET=	install-strip

PORTDOCS=	README.md

PLIST_FILES=	bin/bf2c bin/gen_bf

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
