# Created by: ijliao
# $FreeBSD$

PORTNAME=	epydoc
PORTVERSION=	3.0.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python API documentation generation tool

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS UTF8

UTF8_DESC=	Use UTF-8 instead of iso-8859-1 in HTMLs

NO_STAGE=	yes
.include <bsd.port.options.mk>

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=		epydoc.1 epydocgui.1

.if ${PORT_OPTIONS:MUTF8}
HTMLENCODING?=	utf-8
.endif

post-patch:
.if defined(HTMLENCODING)
	@${GREP} -lR "iso-8859-1" ${WRKSRC}/epydoc | \
		${XARGS} ${REINPLACE_CMD} -e 's|iso-8859-1|${HTMLENCODING}|g'
.endif

post-install:
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
