# ex:ts=8
# Ports collection makefile for:	py-bison
# Date created:			Aug 23, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	bison
PORTVERSION=	0.1.8
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://freenet.mcnabhosting.com/python/pybison/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python-based parsing at the speed of C

LICENSE=	GPLv2

BUILD_DEPENDS=	pyrex>=0.9.6.2:${PORTSDIR}/devel/pyrex

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_BISON=	both
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	0.1

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/bison2py \
		%%PYTHON_SITELIBDIR%%/bison.py \
		%%PYTHON_SITELIBDIR%%/bison.pyc \
		%%PYTHON_SITELIBDIR%%/bison.pyo \
		%%PYTHON_SITELIBDIR%%/bison_.so

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not compile on ia64
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
