# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pefile
DISTVERSION=	1.2.10-123
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python module to read and work with PE files

LICENSE=	MIT

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	${DISTVERSION:C,-,_,g}

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	README

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
