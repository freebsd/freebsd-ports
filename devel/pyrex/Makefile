# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	pyrex
PORTVERSION=	0.9.9
CATEGORIES=	devel lang python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/
PKGNAMEPREFIX=	${PYTHONPKGNAMEPREFIX}
DISTNAME=	Pyrex-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programming Language for writing Python extension modules

LICENSE=	APACHE20

USES=		python:2
USE_PYTHON=	autoplist distutils

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/Manual
	@cd ${WRKSRC}/Doc && ${INSTALL_DATA} ./[^M]* ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/Doc/Manual && ${INSTALL_DATA} ./* ${STAGEDIR}${DOCSDIR}/Manual
	@cd ${WRKSRC}/Demos && ${MAKE} clean
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/Demos -cf - . | \
		${TAR} -C ${STAGEDIR}${EXAMPLESDIR} -xf -

.include <bsd.port.mk>
