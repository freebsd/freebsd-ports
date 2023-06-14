PORTNAME=	ipympl
DISTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Matplotlib Jupyter extension
WWW=		https://github.com/matplotlib/ipympl

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter-packaging>0:devel/py-jupyter-packaging@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipykernel>=4.7:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipywidgets>=7.6.0:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.0.0:math/py-matplotlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-install:
# Enable extension for jupyter lab and notebook
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/jupyter/nbconfig/notebook.d && \
	${INSTALL_DATA} ${WRKSRC}/jupyter-matplotlib.json \
		${STAGEDIR}${PREFIX}/etc/jupyter/nbconfig/notebook.d/
	${INSTALL_DATA}  ${WRKSRC}/ipympl/labextension/package.json \
		${STAGEDIR}${PYTHON_SITELIBDIR}/ipympl/nbextension/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/jupyter/labextensions/ && \
	${LN} -sf ${PYTHON_SITELIBDIR}/ipympl/labextension \
		${STAGEDIR}${PREFIX}/share/jupyter/labextensions/jupyter-matplotlib
	${MKDIR} ${STAGEDIR}${PREFIX}/share/jupyter/nbextensions/ && \
	${LN} -sf ${PYTHON_SITELIBDIR}/ipympl/nbextension \
		${STAGEDIR}${PREFIX}/share/jupyter/nbextensions/jupyter-matplotlib

.include <bsd.port.mk>
