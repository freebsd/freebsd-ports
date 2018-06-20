# $FreeBSD$

PORTNAME=	cmdtest
PORTVERSION=	0.32
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://git.liw.fi/cgi-bin/cgit/cgit.cgi/cmdtest/snapshot/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Black box testing of Unix programs

LICENSE=	GPLv3
LICENSE_FILES=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cliapp>0:devel/py-cliapp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ttystatus>0:devel/py-ttystatus@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cliapp>0:devel/py-cliapp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ttystatus>0:devel/py-ttystatus@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,python,${PYTHON_CMD},g ; s,share/man/,man/," ${WRKSRC}/setup.py

.include <bsd.port.mk>
