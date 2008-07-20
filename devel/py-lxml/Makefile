# Ports collection makefile for:	py-lxml
# Date created:				Feb 18, 2007
# Whom:					Robert Gogolok <gogo@cs.uni-sb.de>
#
# $FreeBSD$
#

PORTNAME=	lxml
PORTVERSION=	2.1
CATEGORIES=	devel python
MASTER_SITES=	http://codespeak.net/lxml/ \
		CHEESESHOP \
		http://pypi.python.org/packages/source/l/lxml/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	Pythonic binding for the libxml2 and libxslt libraries

LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_INSTALLARGS=	-N ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}
PYEASYINSTALL_UNINSTALLARGS=	-q -m -N ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}
PYEASYINSTALL_ARCHDEP=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	CHANGES.txt \
		CREDITS.txt \
		LICENSES.txt \
		TODO.txt \
		README.txt

PYLXML_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
	@${MKDIR} ${DOCSDIR}/doc
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}/doc
.endif

.include <bsd.port.mk>
