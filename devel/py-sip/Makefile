# New ports collection makefile for:	py-sip
# Date created:		Tue Oct  8 09:51:22 SAST 2002
# Whom:			nbm
#
# $FreeBSD$

PORTNAME=	sip
PORTVERSION=	${SIP_VERSION}
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_SIP} ${MASTER_SITE_LOCAL}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${SIP_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python to C and C++ bindings generator

USE_PYTHON=	2.5+

OPTIONS=	DEBUG "Build with debugging symbols" off

DATADIR=	${PREFIX}/share/py-${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
ARGS=		-b ${PREFIX}/bin -d ${PYTHONPREFIX_SITELIBDIR}\
		-e ${PYTHONPREFIX_INCLUDEDIR} -v ${DATADIR}

PORTDOCS=	*

.include "files/bsd.pyqt.mk"
.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
ARGS+=		-u
.endif

do-configure:
	cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${ARGS}

post-configure:
.for item in sipgen siplib
	${REINPLACE_CMD} -e 's|CC = gcc|CC = ${CC}|'\
		-e 's|CXX = g++|CXX = ${CXX}|'\
		-e 's|LINK = g++|LINK = ${CXX}|'\
		${WRKSRC}/${item}/Makefile
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} && cd ${WRKSRC}/doc/html && \
		${COPYTREE_SHARE} \. ${DOCSDIR}
.endif
	${MKDIR} ${DATADIR} &&\
		cd ${PYTHONPREFIX_SITELIBDIR} &&\
		${PYTHON_CMD} -c "import sipconfig" &&\
		${PYTHON_CMD} -O -c "import sipconfig" &&\
		${PYTHON_CMD} -c "import sipdistutils" &&\
		${PYTHON_CMD} -O -c "import sipdistutils"

.include <bsd.port.mk>
