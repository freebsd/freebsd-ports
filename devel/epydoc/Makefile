# ex:ts=8
# Ports collection makefile for:	epydoc
# Date created:			Dec 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	epydoc
PORTVERSION=	3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python API documentation generation tool

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=		epydoc.1 epydocgui.1

OPTIONS=	UTF8 "Use UTF-8 instead of iso-8859-1 in HTMLs" off

HTMLENCODINGFILES=	epydoc/docwriter/html_colorize.py \
			epydoc/docwriter/html.py \
			epydoc/docparser.py

.include <bsd.port.pre.mk>

.if defined(WITH_UTF8)
HTMLENCODING?=	utf-8
.endif
.if defined(HTMLENCODING)
post-patch:
.for f in ${HTMLENCODINGFILES}
	${REINPLACE_CMD} 's,iso-8859-1,${HTMLENCODING},g' ${WRKSRC}/${f}
.endfor
.endif

post-install:
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
