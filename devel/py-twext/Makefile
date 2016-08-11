# $FreeBSD$

PORTNAME=	twext
PORTVERSION=	0.15423
CATEGORIES=	devel python
MASTER_SITES=	http://www.lechner-rau.de/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	axel.rau@chaos1.de
COMMENT=	Extensions to Twisted

LICENSE=	APACHE20

FETCH_DEPENDS=	svn:devel/subversion
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=15.4.0:devel/py-twisted
RUN_DEPENDS=	\
 ${PYTHON_PKGNAMEPREFIX}cffi>=0.6:devel/py-cffi \
 ${PYTHON_PKGNAMEPREFIX}twisted>=15.4.0:devel/py-twisted

DAL_RUN_DEPENDS=	\
 ${PYTHON_PKGNAMEPREFIX}sqlparse>=0.1.11:databases/py-sqlparse
POSTGRES_RUN_DEPENDS=	\
 ${PYTHON_PKGNAMEPREFIX}pg8000>=1.10.2:databases/py-pg8000

OPTIONS_DEFINE=	DAL POSTGRES
DAL_DESC=	Enables use of the Database Abstraction Layer.
POSTGRES=	Enables support for Postgres database connectivity.
OPTIONS_DEFAULT=	DAL POSTGRES
.include <bsd.port.options.mk>

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=yes

SVN_REPOSITORY_URL=	http://svn.calendarserver.org/repository/calendarserver
SVN_TAG3=	twext/trunk
SVN_CMD3=	svn export -r15423

maint-gen-distfile:
	@if [ ! -f "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}" ] ; then \
		${MKDIR} ${WRKDIR} ; cd ${WRKDIR} ; ${RM} -Rf ${WRKDIR}/${DISTNAME} ; \
		${ECHO_MSG} "=> Checking out twext from svn.calendarserver.org/..."; \
		${SVN_CMD3} ${SVN_REPOSITORY_URL}/${SVN_TAG3} > /dev/null ; \
		${MV} trunk ${DISTNAME} ; \
		${ECHO_MSG} "=> Creating tar archive ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}"; \
		cd ${WRKDIR} ; tar -czf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${DISTNAME} ; \
		${RM} -Rf ${WRKDIR}/${DISTNAME} ; \
	else \
		${ECHO_MSG} "===>	${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} found." ; \
	fi

.include <bsd.port.mk>
