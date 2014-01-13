# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	gvgen
PORTVERSION=	0.9
CATEGORIES=	graphics python
MASTER_SITES=	http://software.inl.fr/releases/GvGen/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	An easy python interface to generate dot files

USE_PYTHON=	yes
USE_PYDISTUTILS=easy-install
PYDISTUTILS_PKGVERSION=	0.9
PYDISTUTILS_EGGINFO=	GvGen-${PORTVERSION}-py${PYTHON_VER}.egg-info

PORTDOCS=	user-guide.tex.lyx

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
