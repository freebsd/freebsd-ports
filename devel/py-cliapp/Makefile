PORTNAME=	cliapp
PORTVERSION=	1.20180812.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://git.liw.fi/cgi-bin/cgit/cgit.cgi/cliapp/snapshot/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Python framework for command line utilities
WWW=		https://liw.fi/cliapp/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
NO_ARCH=	yes

USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
