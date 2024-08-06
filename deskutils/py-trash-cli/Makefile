PORTNAME=	trash-cli
DISTVERSION=	0.24.5.26
CATEGORIES=	deskutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	trash_cli-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Command line interface to the freedesktop.org trashcan
WWW=		https://github.com/andreafrancia/trash-cli

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shtab>=1.7.1:devel/py-shtab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.44.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=6.0.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.16.0:devel/py-six@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist pep517
TRASH_CMDS=	trash-empty trash-list trash-restore trash-put trash

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
. for cmd in ${TRASH_CMDS}
	@${SETENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} \
		${STAGEDIR}${PREFIX}/bin/${cmd} --print-completion bash >  ${STAGEDIR}${PREFIX}/share/bash-completion/completions/${cmd}
	@${SETENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} \
		${STAGEDIR}${PREFIX}/bin/${cmd} --print-completion zsh > ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${cmd}
. endfor

.include <bsd.port.mk>
