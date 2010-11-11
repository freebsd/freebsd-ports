# New ports collection makefile for:	py-lzma
# Date created:		28 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	lzma
PORTVERSION=	0.4.2
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Python binding for the LZMA compression library

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	py${PORTNAME}
PYEASYINSTALL_ARCHDEP=	yes
PYEASYINSTALL_EGG=	${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	usage.txt

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
