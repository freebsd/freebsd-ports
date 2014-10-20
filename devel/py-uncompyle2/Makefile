# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	uncompyle2
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/Mysterie/${PORTNAME}/tarball/${HASH}/
PKGNAMEPREFIX=	py-
DISTNAME=	Mysterie-${PORTNAME}-${HASH}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Decompiler for Python's .pyc and .pyo files

HASH=		3956a5a
USES=		python:2
USE_PYTHON=	distutils
REINPLACE_ARGS=	-i ""

pre-patch:
	# Removing blanks at EOL
	${FIND} ${WRKSRC} -type f -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -E 's/[[:blank:]]+$$//g'

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/uncompyle2.py ${STAGEDIR}${PREFIX}/bin/uncompyle2

.include <bsd.port.mk>
