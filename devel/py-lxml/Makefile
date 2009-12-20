# Ports collection makefile for:	py-lxml
# Date created:				Feb 18, 2007
# Whom:					Robert Gogolok <gogo@cs.uni-sb.de>
#
# $FreeBSD$
#

PORTNAME=	lxml
PORTVERSION=	2.2.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	Pythonic binding for the libxml2 and libxslt libraries

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	CHANGES.txt \
		CREDITS.txt \
		LICENSES.txt \
		TODO.txt \
		README.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
