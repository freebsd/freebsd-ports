# New ports collection makefile for:	py-parsedatetime
# Date created:		Feb. 24, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	parsedatetime
PORTVERSION=	0.8.3
CATEGORIES=	devel python
MASTER_SITES=	http://code-bear.com/code/parsedatetime/ \
		http://cheeseshop.python.org/packages/source/p/parsedatetime/ \
		http://parsedatetime.googlecode.com/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python module for parsing 'human readable' date/time expressions

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${PARSEDATETIME_EGG}

PARSEDATETIME_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PARSEDATETIME_EGG=${PARSEDATETIME_EGG} \
		PARSEDATETIME_EGG_VER="${PORTNAME}==${PORTVERSION}"

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
.endif
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
EXAMPLES=	README.txt basic.py with_locale.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
