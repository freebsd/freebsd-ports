# New ports collection makefile for:	py-rbtree
# Date created:				08 Mai 2006
# Whom:					Marcus Alves Grando <mnag@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rbtree
PORTVERSION=	0.8.0
CATEGORIES=	devel python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/r/rbtree/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	A fast tree with ordered data and expanded iterator support

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools \
		pyrexc:${PORTSDIR}/devel/pyrex
RUN_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${PYRBTREE_EGG}

PYRBTREE_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}-${OSINFOS}.egg
OSINFOS=	${OPSYS:L}-${OSRELEASE}-${ARCH}

PLIST_SUB+=	PYRBTREE_EGG=${PYRBTREE_EGG}

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*
.endif

pre-build:
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py setopt -c build -o build-platlib -s lib.${OSINFOS}
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py setopt -c build -o build-temp -s temp.${OSINFOS}-${PYTHON_VER}
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py setopt -c bdist_egg -o plat-name -s ${OSINFOS}
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py setopt -c bdist -o plat-name -s ${OSINFOS}


post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

test:	build
	(cd ${WRKSRC} && ${PYTHON_CMD} test_rbtree.py)

.include <bsd.port.pre.mk>

OSRELEASE!=	uname -r

.include <bsd.port.post.mk>
