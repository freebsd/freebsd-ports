PORTNAME=	ua_parser
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/_/-/}-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Python port of Browserscope's user agent parser
WWW=		https://github.com/ua-parser/uap-python

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
RUN_DEPENDS=	${LOCALBASE}/share/ua_parser/regexes.yaml:devel/ua_parser-core \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
SUB_FILES=	pkg-message

.include <bsd.port.mk>
