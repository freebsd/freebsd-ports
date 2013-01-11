# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mx-base
PORTVERSION=	3.2.5
CATEGORIES=	lang python
MASTER_SITES=	https://downloads.egenix.com/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	egenix-${PORTNAME}-${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	eGenix mx-Extension Series for Python

USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes

PYDISTUTILS_PKGNAME=	egenix-mx-base

PORTDOCS=	COPYRIGHT MANIFEST README LICENSE PKG-INFO

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}/options
OPTIONS_DEFINE=	DOCS ZOPE
ZOPE_DESC=	Use ZOPE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MZOPE}
USE_ZOPE=	yes
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${SED} -e "s;%%PYTHON_SITELIBDIR%%;${PYTHON_SITELIBDIR};g" \
		< ${FILESDIR}/index.html.in > ${DOCSDIR}/index.html
	@${CHMOD} 644 ${DOCSDIR}/index.html
.endif

.include <bsd.port.mk>
