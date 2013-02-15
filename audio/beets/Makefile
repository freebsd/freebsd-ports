# Created by: Mark Felder <feld@feld.me>
# $FreeBSD$

PORTNAME=	beets
PORTVERSION=	1.0.0
CATEGORIES=	audio python

MAINTAINER=	feld@feld.me
COMMENT=	A media library management system for obsessive-compulsive music geeks

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>=0:${PORTSDIR}/audio/py-mutagen \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0:${PORTSDIR}/converters/py-unidecode \
		${PYTHON_PKGNAMEPREFIX}musicbrainzngs>=0:${PORTSDIR}/audio/py-musicbrainzngs \
		${PYTHON_PKGNAMEPREFIX}munkres>=0:${PORTSDIR}/math/py-munkres

USE_PYTHON=	2.7+
USE_PYDISTUTILS=	easy_install

USE_GITHUB=	yes
GH_ACCOUNT=	sampsyo
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	d06ca1e

.include <bsd.port.pre.mk>

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYSETUP} build)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/beet ${PREFIX}/bin/
	${INSTALL} -d ${PYTHONPREFIX_SITELIBDIR}/beets
	cd ${WRKSRC}/build/lib && ${COPYTREE_SHARE} \* ${PYTHONPREFIX_SITELIBDIR}/

.include <bsd.port.post.mk>
