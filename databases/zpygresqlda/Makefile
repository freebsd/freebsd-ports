# New ports collection makefile for: ZPyGreSQLDA
# Date created:		07 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	zpygresqlda
PORTVERSION=	0.3.2
CATEGORIES=	databases
MASTER_SITES=	http://www.zope.org/Members/reedstrm/ZPyGreSQLDA-rjr/
DISTNAME=	ZPyGreSQLDA-0.3-rjr2

MAINTAINER=	nbm@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope
LIB_DEPENDS=	pq.2:${PORTSDIR}/databases/postgresql7

PYTHON_VERSION=	python1.5

# You can change this in the environment
SZOPEBASEDIR?=		www/Zope

# Don't change these
ZOPEBASEDIR=		${PREFIX}/${SZOPEBASEDIR}
ZOPEPRODUCTNAME=	ZPyGreSQLDA
ZOPEPRODUCTDIR=		lib/python/Products

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}

do-build:
	@${ECHO} '*shared*' > ${WRKSRC}/src/Setup
	@${ECHO} '' >> ${WRKSRC}/src/Setup
	@${ECHO} '_pg   pgmodule.c ' \
		'-I${LOCALBASE}/pgsql/include ' \
		'-L${LOCALBASE}/pgsql/lib ' \
		'-lpq -lcrypt' >> ${WRKSRC}/src/Setup
	@(cd ${WRKSRC}/src && \
		make -f Makefile.pre.in boot && \
		make )
	@${CP} ${WRKSRC}/src/_pgmodule.so ${WRKSRC}/

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}/
	@${CP} -Rf ${WRKSRC}/* \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/${ZOPEPRODUCTNAME}/

.include <bsd.port.mk>
