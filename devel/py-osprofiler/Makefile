# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	osprofiler
PORTVERSION=	2.9.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack Profiler Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.7.1:www/py-webob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.14.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.18:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0.7.2<0.8:devel/py-prettytable@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx18>=0:textproc/py-sphinx18@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}openstackdocstheme>=0:textproc/py-openstackdocstheme@${PY_FLAVOR}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/build/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
			"! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.concurrency3>=3.26.0:devel/py-oslo.concurrency3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization2>=2.18.0:devel/py-oslo.serialization2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils3>=3.33.0:devel/py-oslo.utils3@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.26.0:devel/py-oslo.concurrency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
