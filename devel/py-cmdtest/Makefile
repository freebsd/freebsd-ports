# $FreeBSD$

PORTNAME=	cmdtest
PORTVERSION=	0.29
CATEGORIES=	devel
MASTER_SITES=	http://git.liw.fi/cgi-bin/cgit/cgit.cgi/cmdtest/snapshot/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Black box testing of Unix programs

LICENSE=	GPLv3
LICENSE_FILES=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cliapp>0:devel/py-cliapp@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ttystatus>0:devel/py-ttystatus@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cliapp>0:devel/py-cliapp@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ttystatus>0:devel/py-ttystatus@${FLAVOR}

USES=		python:2
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e "s,python,${PYTHON_CMD},g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
