# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eyed3
PORTVERSION=	0.7.5
CATEGORIES=	audio python
MASTER_SITES=	http://eyed3.nicfit.net/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	eyeD3-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python module for processing ID3 tags

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}magic>0:${PORTSDIR}/devel/py-magic

USES=		python:2 tar:tgz
USE_PYTHON=	autoplist distutils

CONFLICTS=	py*-eyed3-06-[0-9]*

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	AUTHORS ChangeLog README.rst
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's/bash/sh/g' ${WRKSRC}/bin/eyeD3
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
