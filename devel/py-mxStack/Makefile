# New ports collection makefile for:	py-mxStack
# Version required:	0.3.0
# Date created:		14 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	mxStack-0.3.0
PKGNAME=	py-mxStack-0.3.0
CATEGORIES=	devel python
MASTER_SITES=	http://starship.skyport.net/~lemburg/

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-aq
WRKSRC=		${WRKDIR}/Stack/mxStack
ALL_TARGET=	sharedmods

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5
STACKDIR=	${PYTHONSCRIPTDIR}/site-packages/Stack
DOCDIR=		${PREFIX}/share/doc/py-mxStack
EXAMPLEDIR=	${PREFIX}/share/examples/py-mxStack

post-extract:
	@${CP} ${FILESDIR}/Setup ${WRKSRC}

do-configure:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} ${MAKE} -f Makefile.pre.in boot)

post-install:
	@${MKDIR} ${STACKDIR}
	${INSTALL_DATA} ${WRKDIR}/Stack/*.py ${STACKDIR}
	@${PREFIX}/bin/python ${PYTHONSCRIPTDIR}/compileall.py ${STACKDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${STACKDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/Stack/Doc/* ${DOCDIR}
.endif

.include <bsd.port.mk>
