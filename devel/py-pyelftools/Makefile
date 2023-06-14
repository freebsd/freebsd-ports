PORTNAME=	pyelftools
PORTVERSION=	0.29
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library for analyzing ELF files and DWARF debugging information
WWW=		https://github.com/eliben/pyelftools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
STRIP=
USES=		python
USE_PYTHON=	distutils autoplist concurrent

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
