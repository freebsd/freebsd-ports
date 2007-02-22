# Ports collection makefile for:	py-lxml
# Date created:				Feb 18, 2007
# Whom:					Robert Gogolok <gogo@cs.uni-sb.de>
#
# $FreeBSD$
#

PORTNAME=	lxml
PORTVERSION=	1.2
CATEGORIES=	devel python
MASTER_SITES=	http://codespeak.net/lxml/ \
		http://cheeseshop.python.org/packages/source/l/lxml/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	Pythonic binding for the libxml2 and libxslt libraries

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

BASEDOCS=	CHANGES.txt \
		CREDITS.txt \
		LICENSES.txt \
		TODO.txt \
		README.txt

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

PYLXML_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}-${OPSYS:L}-${OSRELEASE}-${ARCH}.egg

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYLXML_EGG=${PYLXML_EGG} \
		PYLXML_EGG_VER="${PORTNAME}==${PORTVERSION}"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${BASEDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
	@${MKDIR} ${DOCSDIR}/doc
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}/doc
.endif

.include <bsd.port.pre.mk>

OSRELEASE!=	${DESTDIR}/usr/bin/uname -r

.include <bsd.port.post.mk>
