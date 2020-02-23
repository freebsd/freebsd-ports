# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	uncompyle2
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	py-

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Decompiler for Python's .pyc and .pyo files

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USE_GITHUB=	yes
GH_ACCOUNT=	Mysterie
GH_TAGNAME=	3956a5a
USES=		python:2.7
USE_PYTHON=	distutils
REINPLACE_ARGS=	-i ""

pre-patch:
	# Removing blanks at EOL
	${FIND} ${WRKSRC} -type f -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -E 's/[[:blank:]]+$$//g'

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/uncompyle2.py ${STAGEDIR}${PREFIX}/bin/uncompyle2

.include <bsd.port.mk>
