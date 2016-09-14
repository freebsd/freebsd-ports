# Created by: ghostonthewire <ghostonthewire at gmail dot com>
# $FreeBSD$

PORTNAME=	coil
PORTVERSION=	0.3.20
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ghostonthewire@gmail.com
COMMENT=	Powerful configuration language for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN=		Unfetchable (google code has gone away)

USES=		python
USE_PYTHON=	distutils

PORTDOCS=	README.txt \
		TODO.txt

OPTIONS_DEFINE=	DOCS

post-install:
# docs
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
