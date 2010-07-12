# ex:ts=8
# Ports collection makefile for:	epydoc
# Date created:			Dec 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	epydoc
PORTVERSION=	3.0.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Python API documentation generation tool

OPTIONS=	UTF8 "Use UTF-8 instead of iso-8859-1 in HTMLs" off

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=		epydoc.1 epydocgui.1

.include <bsd.port.pre.mk>

.if defined(WITH_UTF8)
HTMLENCODING?=	utf-8
.endif

post-patch:
.if defined(HTMLENCODING)
	@${GREP} -lR "iso-8859-1" ${WRKSRC}/epydoc | \
		${XARGS} ${REINPLACE_CMD} -e 's|iso-8859-1|${HTMLENCODING}|g'
.endif

post-install:
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
