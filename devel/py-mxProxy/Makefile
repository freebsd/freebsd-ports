# New ports collection makefile for:	py-mxProxy
# Date created:		2 November 2000
# Whom:			Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	mxProxy
PORTVERSION= 	0.2.0
CATEGORIES=	devel python
MASTER_SITES=	http://www.lemburg.com/files/python/
PKGNAMEPREFIX=	py-

MAINTAINER=	johann@egenetics.com

USE_PYTHON=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-aq
WRKSRC=		${WRKDIR}/${PORTNAME:S/^mx//}
CONFIGURE_WRKSRC= ${WRKSRC}/${PORTNAME}
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
ALL_TARGET=	sharedmods

MODULEDIR=	${PYTHON_SITELIBDIR}/${PORTNAME:S/^mx//}
BINMODDIR=	${MODULEDIR}/${PORTNAME}
DOCDIR=		${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLEDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

post-extract:
	@ ${CP} ${PYTHON_LIBDIR}/config/Makefile.pre.in ${CONFIGURE_WRKSRC}

do-configure:
	@ (cd ${CONFIGURE_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE} -f \
	  Makefile.pre.in boot)

do-install:
	@ ${MKDIR} ${MODULEDIR}
	@ ${MKDIR} ${BINMODDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/*.py ${MODULEDIR}
.for file in __init__.py ${PORTNAME}.so
	@ ${INSTALL_DATA} ${BUILD_WRKSRC}/${file} ${BINMODDIR}
.endfor
	@ strip ${BINMODDIR}/*.so
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${MODULEDIR}
	@ ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${MODULEDIR}
	@ ${MKDIR} ${EXAMPLEDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/Examples/* ${EXAMPLEDIR}
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/Doc/* ${DOCDIR}
.endif

.include <bsd.port.mk>
