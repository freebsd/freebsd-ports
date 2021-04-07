PORTNAME=	cmdtest
PORTVERSION=	0.33.s20191128
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://git.liw.fi/cmdtest/snapshot/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-3cba2b5e030b05567057ba2b6720f4a87e6e1f4f

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Black box testing of Unix programs

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cliapp>0:devel/py-cliapp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ttystatus>0:devel/py-ttystatus@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cliapp>0:devel/py-cliapp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ttystatus>0:devel/py-ttystatus@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,python3,${PYTHON_CMD},g ; s,share/man/,man/," ${WRKSRC}/setup.py

.include <bsd.port.mk>
