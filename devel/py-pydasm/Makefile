# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pydasm
PORTVERSION=	1.5
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	libdasm
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	libdasm-${PORTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python interface to libdasm

LICENSE=	BSD2CLAUSE

BROKEN=		Unfetchable (google code has gone away)

USES=		python
USE_PYTHON=	distutils autoplist
WRKSRC_SUBDIR=	${PORTNAME}

PORTDOCS=	README.txt
PORTEXAMPLES=	das.py

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
