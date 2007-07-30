# New ports collection makefile for:	py-rbtree
# Date created:				08 Mai 2006
# Whom:					Marcus Alves Grando <mnag@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rbtree
PORTVERSION=	0.8.0
CATEGORIES=	devel python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/r/rbtree/ \
		http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	A fast tree with ordered data and expanded iterator support

BUILD_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

test:	build
	(cd ${WRKSRC} && ${PYTHON_CMD} test_rbtree.py)

.include <bsd.port.mk>
