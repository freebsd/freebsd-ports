# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fusefs
DISTVERSION=	0.2.1
CATEGORIES=	devel python
MASTER_SITES=	SF/fuse/fuse-python/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	fuse-python-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FUSE Python bindings

USES=		fuse pkgconfig iconv
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

PORTDOCS=	AUTHORS Changelog FAQ INSTALL README.1st README.historic \
		README.new_fusepy_api
PORTEXAMPLES=	_find_fuse_parts.py hello.py xmp.py
DOCSDIR?=	${PREFIX}/share/doc/py-fusefs
EXAMPLESDIR?=	${PREFIX}/share/examples/py-fusefs

post-patch:
	@${REINPLACE_CMD} -e '/libs =/s|$$| + " ${ICONV_LIB}"|'\
		${WRKSRC}/setup.py

post-install:
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
	@${INSTALL} -d ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/example/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
