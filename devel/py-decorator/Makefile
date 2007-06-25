# New ports collection makefile for:	py-decorator
# Date created:		Thu Jun 21 14:49:52 MSD 2007
# Whom:			Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	decorator
PORTVERSION=	2.0.1
CATEGORIES=	devel python
MASTER_SITES=	http://www.phyast.pitt.edu/~micheles/python/ \
		http://pylonshq.com/download/0.9.5/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dsh@vlink.ru
COMMENT=	Better living through Python with decorators

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
USE_ZIP=	yes

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

PYDECORATOR_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYDECORATOR_EGG=${PYDECORATOR_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	documentation.*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
