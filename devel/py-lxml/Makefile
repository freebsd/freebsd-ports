# Ports collection makefile for:	py-lxml
# Date created:				Feb 18, 2007
# Whom:					Robert Gogolok <gogo@cs.uni-sb.de>
#
# $FreeBSD$

PORTNAME=	lxml
PORTVERSION=	2.3.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	Pythonic binding for the libxml2 and libxslt libraries

LICENSE=	BSD

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	CHANGES.txt \
		CREDITS.txt \
		LICENSES.txt \
		TODO.txt \
		README.rst

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
