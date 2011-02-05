# New ports collection makefile for:	tegaki-recognize

# Date created:				15 Aug 2010
# Whom:					Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$
#

PORTNAME=	tegaki
PORTVERSION=	0.3.1
CATEGORIES=	japanese python
MASTER_SITES=	http://www.tegaki.org/releases/${PORTVERSION}/
PKGNAMESUFFIX=	-recognize
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Open-Source Chinese and Japanese Handwriting Recognition

LIB_DEPENDS=	zinnia.0:${PORTSDIR}/japanese/zinnia
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/tegakigtk/recognizer.py:${PORTSDIR}/japanese/py-tegaki-gtk

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME}_recognize

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
