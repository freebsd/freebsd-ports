# New ports collection makefile for:	linux-oracle-instantclient-sdk
# Date created:				2005-04-26
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		instantclient
PORTVERSION=		10.1.0.3
CATEGORIES=		databases
MASTER_SITES=		#http://www.oracle.com/technology/software/tech/oci/instantclient/
PKGNAMEPREFIX=		linux-oracle-
PKGNAMESUFFIX=		-sdk
DISTNAME=		${PORTNAME}${PKGNAMESUFFIX}-linux32-${PORTVERSION}
DIST_SUBDIR=		oracle

MAINTAINER=		nork@FreeBSD.org
COMMENT=		Oracle 10 InstantClient SDK. Works with Oracle RDBMS 8.1.2+

RUN_DEPENDS=		${LINUXBASE}/usr/lib/oracle/${PORTVERSION}/client/lib/libocci.so.10.1:${.CURDIR}/../linux-oracle-instantclient-basic

ONLY_FOR_ARCHS=		i386
# Couldn't test for IA64, so commented it out
# ONLY_FOR_ARCHS+=	ia64
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes

RESTRICTED=		Packaging prohibited by Oracle license

USE_ZIP=		yes
USE_LINUX_PREFIX=	yes

INCS_LIST=		nzerror.h \
			nzt.h \
			occi.h \
			occiAQ.h \
			occiCommon.h \
			occiControl.h \
			occiData.h \
			occiObjects.h \
			oci.h \
			oci1.h \
			oci8dp.h \
			ociap.h \
			ociapr.h \
			ocidef.h \
			ocidem.h \
			ocidfn.h \
			ociextp.h \
			ocikpr.h \
			ocixmldb.h \
			odci.h \
			oratypes.h \
			ori.h \
			orid.h \
			orl.h \
			oro.h \
			ort.h \
			xa.h

DEMO_LIST=		cdemo81.c \
			demo.mk \
			occidemo.sql \
			occidemod.sql \
			occidml.cpp

WRKSRC=			${WRKDIR}/instantclient10_1/sdk

INSTLIBSDIR=		${PREFIX}/usr/lib/oracle/${PORTVERSION}/client/lib
INSTINCSDIR=		${PREFIX}/usr/include/oracle/${PORTVERSION}/client
INSTDEMODIR=		${PREFIX}/usr/share/oracle/${PORTVERSION}/client

PLIST_SUB=		PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
ECHO_MSG=		${PRINTF} %b

IGNORE+=		\n\n-=< MARKED AS IGNORED: >=-\n
IGNORE+=		\n
IGNORE+=		Due to Oracle license restrictions, you must fetch the source \n
IGNORE+=		distribution manually.  Please access  \n
IGNORE+=		http://www.oracle.com/technology/software/tech/oci/instantclient/index.html \n
IGNORE+=		with a web browser and follow the link for the \n
IGNORE+=		\"${DISTFILES}\".  \n
IGNORE+=		You will be required to register and log in, \n
IGNORE+=		but you can create an account on that page.  \n
IGNORE+=		After registration and accepting the Oracle License, \n
IGNORE+=		download the distribution file, \n ${DISTFILES}, \n
IGNORE+=		into ${DISTDIR}/${DIST_SUBDIR}/ \n
IGNORE+=		and then restart this installation\n\n
.endif

do-install:
			${MKDIR} -m 0755 ${INSTINCSDIR} ${INSTDEMODIR}
			${LN} -s libclntsh.so.10.1 ${INSTLIBSDIR}/libclntsh.so
			${LN} -s libocci.so.10.1 ${INSTLIBSDIR}/libocci.so
.for i in ${INCS_LIST}
			${INSTALL_DATA} ${WRKSRC}/include/${i} ${INSTINCSDIR}/${i}
.endfor
.for i in ${DEMO_LIST}
			${INSTALL_DATA} ${WRKSRC}/demo/${i} ${INSTDEMODIR}/${i}
.endfor

.include <bsd.port.post.mk>
