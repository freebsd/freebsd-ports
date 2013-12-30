# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stevedore
PORTVERSION=	0.11
#PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Manage dynamic plugins for Python applications

LICENSE=	APACHE20

BUILD_DEPENDS=	${PKGNAMEPREFIX}argparse>=1.1:${PORTSDIR}/devel/py-argparse
TEST_DEPENDS=	${PKGNAMEPREFIX}coverage>=3.5.3:${PORTSDIR}/devel/py-coverage \
		${PKGNAMEPREFIX}mock>=1.0.1:${PORTSDIR}/devel/py-mock \
		${PKGNAMEPREFIX}nose>=1.3.0:${PORTSDIR}/devel/py-nose \
		${PKGNAMEPREFIX}tox>=1.5.0:${PORTSDIR}/devel/py-tox

OPTIONS_DEFINE=	DOCS
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

TOX_CMD=	${LOCALBASE}/bin/tox

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz \
		sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
PYDISTUTILS_BUILD_TARGET+=	build_sphinx --all-files --fresh-env

post-install:
	@cd ${WRKSRC}/build/sphinx/html && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

regression-test: build
	@cd ${WRKSRC} && \
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},1' \
		-e 's,%%PYTHON_SUFFIX%%,${PYTHON_SUFFIX},1' \
		-e 's,%%WRKSRC%%,${WRKSRC},1' -i.bak tox.ini && \
	${TOX_CMD}

.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.include <bsd.port.post.mk>
