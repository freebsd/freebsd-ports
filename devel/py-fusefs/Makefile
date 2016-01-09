# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fusefs
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF/fuse/fuse-python/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	fuse-python-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FUSE Python bindings

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		fuse pkgconfig python iconv
USE_PYTHON=	distutils autoplist

PORTDOCS=	AUTHORS Changelog FAQ INSTALL README.1st README.historic \
		README.new_fusepy_api
PORTEXAMPLES=	_find_fuse_parts.py hello.py xmp.py
DOCSDIR?=	${PREFIX}/share/doc/py-fusefs
EXAMPLESDIR?=	${PREFIX}/share/examples/py-fusefs

post-patch:
	@${REINPLACE_CMD} -e '/libs =/s|$$| + " ${ICONV_LIB}"|'\
		${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/fuseparts/_fusemodule.so
post-install-DOCS-on:
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
post-install-EXAMPLES-on:
	@${INSTALL} -d ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/example/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
