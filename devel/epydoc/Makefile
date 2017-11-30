# Created by: ijliao
# $FreeBSD$

PORTNAME=	epydoc
PORTVERSION=	3.0.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python API documentation generation tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python:2.7
USE_PYTHON=	distutils

OPTIONS_DEFINE=	DOCS UTF8

UTF8_DESC=	Use UTF-8 instead of iso-8859-1 in HTMLs

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUTF8}
HTMLENCODING?=	utf-8
.endif

post-patch:
.if defined(HTMLENCODING)
	@${GREP} -lR "iso-8859-1" ${WRKSRC}/epydoc | \
		${XARGS} ${REINPLACE_CMD} -e 's|iso-8859-1|${HTMLENCODING}|g'
.endif

post-install:
	(cd ${WRKSRC}/man && ${INSTALL_MAN} epydoc.1 epydocgui.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
