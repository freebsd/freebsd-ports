# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	interface
PORTVERSION=	1.3
CATEGORIES=	devel python
MASTER_SITES=	http://www.lysator.liu.se/~tab/erlang/py_interface/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py_${PORTNAME}-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Python implementation of an Erlang node

LICENSE=	GPLv2

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	py_${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/py_${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py_${PORTNAME}

post-install:
	@${TRUE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
