# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pew
PORTVERSION=	1.1.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool to manage multiple virtualenvs

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}virtualenv>=1.11:devel/py-virtualenv@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv-clone>=0.2.5:devel/py-virtualenv-clone@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python shebangfix

SHEBANG_FILES=	pew/shell_config/complete_deploy

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.shutil_get_terminal_size>=0:devel/py-backports.shutil_get_terminal_size@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathlib>=0:devel/py-pathlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shutilwhich>=0:sysutils/py-shutilwhich@${FLAVOR}
.endif

.include <bsd.port.post.mk>
