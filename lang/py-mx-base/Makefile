# New ports collection makefile for:	py-mxTextTools
# Version required:	1.1.1
# Date created:		12 May 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	mxTextTools-1.1.1
PKGNAME=	py-mxTextTools-1.1.1
CATEGORIES=	textproc python
MASTER_SITES=	http://starship.skyport.net/~lemburg/

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-aq
WRKSRC=		${WRKDIR}/TextTools/mxTextTools
ALL_TARGET=	sharedmods

PYTHONSCRIPTDIR=	${PREFIX}/lib/python1.5
TEXTTOOLSDIR=	${PYTHONSCRIPTDIR}/site-packages/TextTools
DOCDIR=		${PREFIX}/share/doc/py-mxTextTools
EXAMPLEDIR=	${PREFIX}/share/examples/py-mxTextTools

post-extract:
	@${CP} ${FILESDIR}/Setup ${WRKSRC}

do-configure:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} ${MAKE} -f Makefile.pre.in boot)

post-install:
	@${MKDIR} ${TEXTTOOLSDIR}
	${INSTALL_DATA} ${WRKDIR}/TextTools/*.py ${TEXTTOOLSDIR}
	@${MKDIR} ${TEXTTOOLSDIR}/Constants
	${INSTALL_DATA} ${WRKDIR}/TextTools/Constants/*.py ${TEXTTOOLSDIR}/Constants
	@${PREFIX}/bin/python ${PYTHONSCRIPTDIR}/compileall.py ${TEXTTOOLSDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${TEXTTOOLSDIR}
	@${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKDIR}/TextTools/Examples/* ${EXAMPLEDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/TextTools/Doc/* ${DOCDIR}
.endif

.include <bsd.port.mk>
