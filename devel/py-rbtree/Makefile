# New ports collection makefile for:	py-rbtree
# Date created:				08 Mai 2006
# Whom:					Marcus Alves Grando <mnag@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rbtree
PORTVERSION=	0.7
CATEGORIES=	devel python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/r/rbtree/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A fast tree with ordered data and expanded iterator support

BUILD_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex

DIST_SUBDIR=	python
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/rbtree.so

PORTDOCS=	*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

test:	build
	(cd ${WRKSRC} && ${PYTHON_CMD} test_rbtree.py)

.include <bsd.port.mk>
