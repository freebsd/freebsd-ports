# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	itools
PORTVERSION=	0.75.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@fbsd.es
COMMENT=	Python library Provides Wide Range Of Capabilities

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=  ${LOCALBASE}/include/poppler/goo/gtypes.h:${PORTSDIR}/graphics/poppler \
		${LOCALBASE}/include/git2.h:${PORTSDIR}/devel/libgit2 \
		${PYTHON_PKGNAMEPREFIX}reportlab2>=2.3:${PORTSDIR}/print/py-reportlab2 \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}gobject>=2.16.1:${PORTSDIR}/devel/py-gobject \
		gettext:${PORTSDIR}/devel/gettext \
		python:${PORTSDIR}/lang/python
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libglib-2.0.so:${PORTSDIR}/devel/glib20 \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libwv2.so:${PORTSDIR}/textproc/wv2

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/poppler
LDFLAGS+=	-L${LOCALBASE}/lib

USES=	pkgconfig python:2.7+
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	DOCS

PORTDOCS=	INSTALL.txt LICENSE.txt MANIFEST README.rst RELEASE-0.75.0 \
		RELEASE-0.75.1 RELEASE-0.75.2 UPGRADE-0.75.0

.include <bsd.port.options.mk>

post-install:
.for f in office pdf web xml
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/${f}/*.so
.endfor

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

regression-test: build
	cd ${WRKSRC}/test && ${PYTHON_CMD} test.py

.include <bsd.port.mk>
