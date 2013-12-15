# Created by: rene
# $FreeBSD$

PORTNAME=	bf2c
PORTVERSION=	1.3.1
CATEGORIES=	lang

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Optimizing BrainF*ck to C compiler

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	rene0
GH_COMMIT=	4761081
USE_XZ=		yes

MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
