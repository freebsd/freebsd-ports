# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redis
PORTVERSION=	2.10.1
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python client for Redis key-value store

LICENSE=	MIT

OPTIONS_DEFINE=	HIREDIS HTMLDOCS
HIREDIS_DESC=	High performance response parser (via hiredis)
HTMLDOCS_DESC=	Build and install API docs using Sphinx
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
DOCGEN=		${LOCALBASE}/bin/sphinx-apidoc

HIREDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hiredis>0:${PORTSDIR}/databases/py-hiredis

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	andymccurdy
GH_PROJECT=	${PORTNAME}-py
GH_COMMIT=	e7589d7

.include <bsd.port.options.mk>
.if !empty(PORT_OPTIONS:MHTMLDOCS)
.	if empty(PORT_OPTIONS:MDOCS)
IGNORE=	you cannot build documentation with DOCS option disabled
.	endif
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sphinx>0:${PORTSDIR}/textproc/py-sphinx
BUILD_DEPENDS+= ${PYTHON_PKGNAMEPREFIX}MarkupSafe>0:${PORTSDIR}/textproc/py-MarkupSafe
PORTDOCS=	*
USES+=		gmake
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

post-build:
.if ${PORT_OPTIONS:MHTMLDOCS}
	@${ECHO_CMD} "Building documentation"
	@cd ${WRKSRC} && ${DOCGEN} -o apidocs -F -H 'redis-py' \
		-V ${PORTVERSION} -A '2014, Andy McCurdy, Mahdi Yusuf' \
		-R ${PORTVERSION} redis

	cd ${WRKSRC}/apidocs && ${MAKE_CMD} html
.endif

post-install:
.if ${PORT_OPTIONS:MHTMLDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${RM} ${WRKSRC}/apidocs/_build/html/.buildinfo
	@cd ${WRKSRC}/apidocs/_build/html && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
