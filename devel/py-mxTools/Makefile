# New ports collection makefile for:	py-mxTools
# Date created:		20 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mxTools
PORTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	http://starship.python.net/~lemburg/
PKGNAMEPREFIX=	py-

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-aq
WRKSRC=		${WRKDIR}/NewBuiltins/mxTools
ALL_TARGET=	sharedmods

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5
TOOLSDIR=	${PYTHONSCRIPTDIR}/site-packages/NewBuiltins
DOCDIR=		${PREFIX}/share/doc/py-mxTools
EXAMPLEDIR=	${PREFIX}/share/examples/py-mxTools

post-extract:
	@${CP} ${FILESDIR}/Setup ${WRKSRC}

do-configure:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} ${MAKE} -f Makefile.pre.in boot)

do-install:
	@${MKDIR} ${TOOLSDIR}
	${INSTALL_DATA} ${WRKDIR}/NewBuiltins/*.py ${TOOLSDIR}
	@${MKDIR} ${TOOLSDIR}/mxTools
.for file in __init__.py mxTools.so xmap.so
	${INSTALL_DATA} ${WRKDIR}/NewBuiltins/mxTools/${file} ${TOOLSDIR}/mxTools
.endfor
	@${PREFIX}/bin/python ${PYTHONSCRIPTDIR}/compileall.py ${TOOLSDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${TOOLSDIR}
	@${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKDIR}/NewBuiltins/Examples/* ${EXAMPLEDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/NewBuiltins/Doc/* ${DOCDIR}
.endif

.include <bsd.port.mk>
