# New ports collection makefile for:	py-mxDateTime
# Date created:		12 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mxDateTime
PORTVERSION=	1.3.0
CATEGORIES=	devel python
MASTER_SITES=	http://starship.python.net/~lemburg/
PKGNAMEPREFIX=	py-

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-aq
WRKSRC=		${WRKDIR}/DateTime/mxDateTime
ALL_TARGET=	sharedmods

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5
DATETIMEDIR=	${PYTHONSCRIPTDIR}/site-packages/DateTime
DOCDIR=		${PREFIX}/share/doc/py-mxDateTime
EXAMPLEDIR=	${PREFIX}/share/examples/py-mxDateTime

post-extract:
	@${CP} ${FILESDIR}/Setup ${WRKSRC}

do-configure:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} ${MAKE} -f Makefile.pre.in boot)

do-install:
	@${MKDIR} ${DATETIMEDIR}
	${INSTALL_DATA} ${WRKDIR}/DateTime/*.py ${DATETIMEDIR}
	@${MKDIR} ${DATETIMEDIR}/mxDateTime
.for file in __init__.py mxDateTime.so
	${INSTALL_DATA} ${WRKDIR}/DateTime/mxDateTime/${file} ${DATETIMEDIR}/mxDateTime
.endfor
	@${PREFIX}/bin/python ${PYTHONSCRIPTDIR}/compileall.py ${DATETIMEDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${DATETIMEDIR}
	@${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKDIR}/DateTime/Examples/* ${EXAMPLEDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/DateTime/Doc/* ${DOCDIR}
.endif

.include <bsd.port.mk>
