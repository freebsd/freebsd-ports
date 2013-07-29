# Created by: Robert Gogolok <gogo@cs.uni-sb.de>
# $FreeBSD$

PORTNAME=	lxml
PORTVERSION=	3.2.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Pythonic binding for the libxml2 and libxslt libraries

LICENSE=	BSD

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		xslt:${PORTSDIR}/textproc/libxslt

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*
DOCS_FILES=	CHANGES.txt CREDITS.txt TODO.txt README.rst

.include <bsd.port.pre.mk>

post-install:
.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${DOCS_FILES:S,^,${WRKSRC}/,} ${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
