# ex:ts=8
# Ports collection makefile for:	epydoc
# Date created:			Dec 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	epydoc
PORTVERSION=	2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python API documentation generation tool

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=	epydoc.1 epydocgui.1

post-install:
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
