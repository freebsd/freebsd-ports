# New ports collection makefile for: ZPyGreSQLDA
# Date created:		07 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	zpygresqlda
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	databases www zope
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
	@${ECHO_CMD} '*shared*' > ${WRKSRC}/src/Setup
	@${ECHO_CMD} '' >> ${WRKSRC}/src/Setup
	@${ECHO_CMD} '_pg   pgmodule.c ' \
		'-I${LOCALBASE}/include ' \
		'-L${LOCALBASE}/lib ' \
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
