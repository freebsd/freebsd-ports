# New ports collection makefile for:	py-mx-base
# Date created:		18 March 2001
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mx-base
PORTVERSION=	2.0.5
CATEGORIES=	lang python
MASTER_SITES=	http://www.egenix.com/files/python/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	tg
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	egenix-${PORTNAME}-${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org
COMMENT=	The eGenix mx-Extension Series for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
.if defined(WITH_ZOPE)
USE_ZOPE=	yes
.endif

DOCDIR=		${PREFIX}/share/doc/py-mx
MXHDRDIR=	${PYTHONPREFIX_SITELIBDIR}/mx/stdlib

post-install:
	@${MKDIR} ${DOCDIR}
	@${SED} -e "s;%%PYTHON_SITELIBDIR%%;${PYTHON_SITELIBDIR};g" \
		< ${FILESDIR}/index.html.in > ${DOCDIR}/index.html
	@${CHMOD} 644 ${DOCDIR}/index.html
	@${MKDIR} ${MXHDRDIR}
.for file in mx.h mxh.h mxpyapi.h mxstdlib.h
	${INSTALL_DATA} ${WRKSRC}/mx/stdlib/${file} ${MXHDRDIR}
.endfor

.include <bsd.port.mk>
