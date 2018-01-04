# Created by: blubee <hello@blubee.me>
# $FreeBSD$

PORTNAME=	pycanberra
DISTVERSION=	1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	hello@blubee.me
COMMENT=	Very basic wrapper for libcanberra

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	autoplist distutils optsuffix

USE_GITHUB=	yes
GH_ACCOUNT=	totdb
GH_TAGNAME=	88c53cd

post-patch:
	@(cd ${WRKSRC} && ${MKDIR} ${WRKSRC}/pycanberra && \
	${MV} pycanberra.py ${WRKSRC}/pycanberra && \
	${TOUCH} __init__.py)

.include <bsd.port.mk>
