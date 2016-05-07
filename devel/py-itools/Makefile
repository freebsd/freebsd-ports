# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	itools
PORTVERSION=	0.75.2
PORTREVISION=	6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@fbsd.es
COMMENT=	Python library Provides Wide Range Of Capabilities

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=  ${LOCALBASE}/include/poppler/goo/gtypes.h:graphics/poppler \
		${LOCALBASE}/include/git2.h:devel/libgit2 \
		${PYTHON_PKGNAMEPREFIX}reportlab2>=2.3:print/py-reportlab2 \
		${PYTHON_PKGNAMEPREFIX}pygit2>0:devel/py-pygit2 \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}xlrd>0:textproc/py-xlrd \
		${PYTHON_PKGNAMEPREFIX}magic>0:devel/py-magic \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}gobject>=2.16.1:devel/py-gobject \
		${LOCALBASE}/bin/git:devel/git \
		xapian-bindings>1.0.8:databases/xapian-bindings
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libglib-2.0.so:devel/glib20 \
		libsoup-2.4.so:devel/libsoup \
		libwv2.so:textproc/wv2

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/poppler
LDFLAGS+=	-L${LOCALBASE}/lib

USES=		gettext-tools:run pkgconfig python:2.7+
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	INSTALL.txt MANIFEST README.rst RELEASE-0.75.0 \
		RELEASE-0.75.1 RELEASE-0.75.2 UPGRADE-0.75.0
PORTEXAMPLES=	*

post-install:
.for f in office pdf web xml
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/${f}/*.so
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/docs/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

regression-test: build
	cd ${WRKSRC}/test && ${PYTHON_CMD} test.py

.include <bsd.port.mk>
