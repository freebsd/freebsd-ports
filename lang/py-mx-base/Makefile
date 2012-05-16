# New ports collection makefile for:	py-mx-base
# Date created:		18 March 2001
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mx-base
PORTVERSION=	3.2.4
CATEGORIES=	lang python
MASTER_SITES=	http://downloads.egenix.com/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	egenix-${PORTNAME}-${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	The eGenix mx-Extension Series for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
.if defined(WITH_ZOPE)
USE_ZOPE=	yes
.endif

PYDISTUTILS_PKGNAME=	egenix-mx-base

PORTDOCS=	COPYRIGHT MANIFEST README LICENSE PKG-INFO

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${SED} -e "s;%%PYTHON_SITELIBDIR%%;${PYTHON_SITELIBDIR};g" \
		< ${FILESDIR}/index.html.in > ${DOCSDIR}/index.html
	@${CHMOD} 644 ${DOCSDIR}/index.html
.endif

.include <bsd.port.mk>
