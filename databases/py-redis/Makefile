# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	2.10.3
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python client for Redis key-value store

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS HIREDIS
HIREDIS_DESC=	High performance response parser (via hiredis)
DOCGEN=		${LOCALBASE}/bin/sphinx-apidoc

HIREDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hiredis>0:${PORTSDIR}/databases/py-hiredis

USES=		python
USE_PYTHON=	distutils autoplist concurrent

USE_GITHUB=	yes
GH_ACCOUNT=	andymccurdy
GH_PROJECT=	${PORTNAME}-py

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sphinx>0:${PORTSDIR}/textproc/py-sphinx
BUILD_DEPENDS+= ${PYTHON_PKGNAMEPREFIX}MarkupSafe>0:${PORTSDIR}/textproc/py-MarkupSafe
PORTDOCS=	*
USES+=		gmake
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

post-build:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_CMD} "Building documentation"
	@cd ${WRKSRC} && ${DOCGEN} -o apidocs -F -H 'redis-py' \
		-V ${PORTVERSION} -A '2014, Andy McCurdy, Mahdi Yusuf' \
		-R ${PORTVERSION} redis

	cd ${WRKSRC}/apidocs && ${MAKE_CMD} html
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${RM} ${WRKSRC}/apidocs/_build/html/.buildinfo
	@cd ${WRKSRC}/apidocs/_build/html && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
