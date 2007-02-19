# Ports collection makefile for:	py-lxml
# Date created:				Feb 18, 2007
# Whom:					Robert Gogolok <gogo@cs.uni-sb.de>
#
# $FreeBSD$
#

PORTNAME=	lxml
PORTVERSION=	1.1.2
CATEGORIES=	devel python
MASTER_SITES=	http://codespeak.net/lxml/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	Pythonic binding for the libxml2 and libxslt libraries

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		 xslt.2:${PORTSDIR}/textproc/libxslt

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

BASEDOCS=	CHANGES.txt \
		CREDITS.txt \
		LICENSES.txt \
		TODO.txt \
		README.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${BASEDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
	@${MKDIR} ${DOCSDIR}/doc
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}/doc
.endif

.include <bsd.port.mk>
