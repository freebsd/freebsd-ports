# New ports collection makefile for:	py-mx-base
# Date created:		18 March 2001
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mx-base
PORTVERSION=	3.1.2
CATEGORIES=	lang python
MASTER_SITES=	http://downloads.egenix.com/python/
MASTER_SITE_SUBDIR=	tg
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	egenix-${PORTNAME}-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	The eGenix mx-Extension Series for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
.if defined(WITH_ZOPE)
USE_ZOPE=	yes
.endif

PYDISTUTILS_PKGNAME=	egenix-mx-base

DOCDIR=		${PREFIX}/share/doc/py-mx

post-install:
	@${MKDIR} ${DOCDIR}
	@${SED} -e "s;%%PYTHON_SITELIBDIR%%;${PYTHON_SITELIBDIR};g" \
		< ${FILESDIR}/index.html.in > ${DOCDIR}/index.html
	@${CHMOD} 644 ${DOCDIR}/index.html

.include <bsd.port.mk>
