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

USE_PYTHON=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-aq
WRKSRC=		${WRKDIR}/NewBuiltins/mxTools
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD}
ALL_TARGET=	sharedmods

TOOLSDIR=	${PYTHON_SITELIBDIR}/NewBuiltins
DOCDIR=		${PREFIX}/share/doc/py-mxTools
EXAMPLEDIR=	${PREFIX}/share/examples/py-mxTools

post-extract:
	@${CP} ${FILESDIR}/Setup ${WRKSRC}
	@${CP} ${PYTHON_LIBDIR}/config/Makefile.pre.in ${WRKSRC}

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE} -f Makefile.pre.in boot)

do-install:
	@${MKDIR} ${TOOLSDIR}
	${INSTALL_DATA} ${WRKDIR}/NewBuiltins/*.py ${TOOLSDIR}
	@${MKDIR} ${TOOLSDIR}/mxTools
.for file in __init__.py mxTools.so xmap.so
	${INSTALL_DATA} ${WRKDIR}/NewBuiltins/mxTools/${file} ${TOOLSDIR}/mxTools
.endfor
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${TOOLSDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${TOOLSDIR}
	@${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKDIR}/NewBuiltins/Examples/* ${EXAMPLEDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/NewBuiltins/Doc/* ${DOCDIR}
.endif

.include <bsd.port.mk>
