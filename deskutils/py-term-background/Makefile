# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	term-background
PORTVERSION=	1.0.1
CATEGORIES=	deskutils python shells
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Shell scripts and Python module to figure out terminal background

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	rocky
GH_PROJECT=	shell-term-background

USES=		python:3.7+ shebangfix
USE_PYTHON=	distutils
SHEBANG_FILES=	term-background.*

NO_ARCH=	yes
MAKE_ENV+=	PYTHON=${PYTHON_CMD}

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/term-background.* ${STAGEDIR}${DATADIR}

do-test: install
	(cd ${WRKSRC} && py.test)

.include <bsd.port.mk>
