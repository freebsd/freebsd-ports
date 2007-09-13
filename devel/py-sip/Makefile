# New ports collection makefile for:	py-sip
# Date created:		Tue Oct  8 09:51:22 SAST 2002
# Whom:			nbm
#
# $FreeBSD$

PORTNAME=	sip
PORTVERSION=	4.7
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/sip4/ \
		http://freebsd.ricin.com/ports/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	danny@ricin.com
COMMENT=	Python to C and C++ bindings generator

USE_PYTHON=	2.5+

OPTIONS=	DEBUG "Build with debugging symbols" off

DATADIR=	${PREFIX}/share/py-${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
ARGS=		-b ${PREFIX}/bin -d ${PYTHON_SITELIBDIR}\
		-e ${PYTHON_INCLUDEDIR} -v ${DATADIR}

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
ARGS+=		-u
.endif

do-configure:
	cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${ARGS}

post-configure:
	for item in sipgen siplib; do\
		${REINPLACE_CMD} -e 's|CC = gcc|CC = ${CC}|'\
		-e 's|CXX = g++|CXX = ${CXX}|'\
		-e 's|LINK = g++|LINK = ${CXX}|'\
		${WRKSRC}/$${item}/Makefile; done

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} && cd ${WRKSRC} && ${INSTALL_DATA}\
		doc/default.css doc/sipref.txt doc/sipref.html\
		NEWS LICENSE ${DOCSDIR}
.endif
	${MKDIR} ${DATADIR} &&\
		cd ${PYTHON_SITELIBDIR} &&\
		${PYTHON_CMD} -c "import sipconfig" &&\
		${PYTHON_CMD} -O -c "import sipconfig" &&\
		${PYTHON_CMD} -c "import sipdistutils" &&\
		${PYTHON_CMD} -O -c "import sipdistutils"

.include <bsd.port.post.mk>
