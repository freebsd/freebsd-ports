# $FreeBSD$

PORTNAME=	qmasm
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0-34
DISTVERSIONSUFFIX=	-gb02225f
CATEGORIES=	lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum macro assembler for D-Wave systems

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PuLP>0:math/py-PuLP@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	lanl
USE_PYTHON=	distutils noflavors autoplist

POST_PLIST=	fix-plist

fix-plist: # https://github.com/lanl/qmasm/issues/9
	@${REINPLACE_CMD} -E "s|^bin/([a-z0-9-]*).py$$|bin/\1|" ${TMPPLIST}

.include <bsd.port.mk>
