# New ports collection makefile for:	py-mxStack
# Date created:		14 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mxStack
PORTVERSION=	0.3.0
CATEGORIES=	devel python
MASTER_SITES=	http://starship.python.net/~lemburg/
PKGNAMEPREFIX=	py-

MAINTAINER=	tg@FreeBSD.org

USE_PYTHON=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-aq
WRKSRC=		${WRKDIR}/Stack/mxStack
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD}
ALL_TARGET=	sharedmods

STACKDIR=	${PYTHON_SITELIBDIR}/Stack
DOCDIR=		${PREFIX}/share/doc/py-mxStack
EXAMPLEDIR=	${PREFIX}/share/examples/py-mxStack

post-extract:
	@${CP} ${FILESDIR}/Setup ${WRKSRC}
	@${CP} ${PYTHON_LIBDIR}/config/Makefile.pre.in ${WRKSRC}

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE} -f Makefile.pre.in boot)

do-install:
	@${MKDIR} ${STACKDIR}
	${INSTALL_DATA} ${WRKDIR}/Stack/*.py ${STACKDIR}
	@${MKDIR} ${STACKDIR}/mxStack
.for file in __init__.py mxStack.so
	${INSTALL_DATA} ${WRKDIR}/Stack/mxStack/${file} ${STACKDIR}/mxStack
.endfor
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${STACKDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${STACKDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/Stack/Doc/* ${DOCDIR}
.endif

.include <bsd.port.mk>
