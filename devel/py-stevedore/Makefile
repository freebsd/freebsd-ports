# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stevedore
PORTVERSION=	0.15
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Manage dynamic plugins for Python applications

LICENSE=	APACHE20

BUILD_DEPENDS=	${PKGNAMEPREFIX}pbr>0:${PORTSDIR}/devel/py-pbr
TEST_DEPENDS=	${PKGNAMEPREFIX}coverage>=3.5.3:${PORTSDIR}/devel/py-coverage \
		${PKGNAMEPREFIX}mock>=1.0.1:${PORTSDIR}/devel/py-mock \
		${PKGNAMEPREFIX}nose>=1.3.0:${PORTSDIR}/devel/py-nose \
		${PKGNAMEPREFIX}tox>=1.5.0:${PORTSDIR}/devel/py-tox

OPTIONS_DEFINE=	DOCS
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

TOX_CMD=	${LOCALBASE}/bin/tox

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz \
		sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	*
PYDISTUTILS_BUILD_TARGET+=	build_sphinx --all-files --fresh-env

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/build/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

regression-test: build
	@cd ${WRKSRC} && \
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},1' \
		-e 's,%%PYTHON_SUFFIX%%,${PYTHON_SUFFIX},1' \
		-e 's,%%WRKSRC%%,${WRKSRC},1' -i.bak tox.ini && \
	${TOX_CMD}

.include <bsd.port.mk>
