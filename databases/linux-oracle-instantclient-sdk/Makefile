# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	instantclient
PORTVERSION=	${ORACLEVERSION}.${DISTDATE}
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	#http://www.oracle.com/technology/software/tech/oci/instantclient/
PKGNAMEPREFIX=	linux-oracle-
PKGNAMESUFFIX=	-sdk
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${LINUXARCH}-${ORACLEVERSION}-${DISTDATE}
DIST_SUBDIR=	oracle

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Oracle 10 InstantClient SDK. Works with Oracle RDBMS 8.1.2+

RUN_DEPENDS=	${LINUXBASE}/usr/lib/oracle/${ORACLEVERSION}/client/lib/libocci.so.10.1:databases/linux-oracle-instantclient-basic

NOFETCHFILES=	${DISTNAME}${EXTRACT_SUFX}
ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
DISTINFO_FILE=	${MASTERDIR}/distinfo.${ARCH}

RESTRICTED=	Packaging prohibited by Oracle license

USES=		zip
USE_LINUX_PREFIX=	yes

ORACLEVERSION=	10.2.0.3

INCS_LIST=	nzerror.h \
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

DEMO_LIST=	cdemo81.c	\
		demo.mk		\
		occidemo.sql	\
		occidemod.sql	\
		occidml.cpp	\
		occiobj.cpp	\
		occiobj.typ

WRKSRC=		${WRKDIR}/instantclient_10_2/sdk

INSTLIBSDIR=	${STAGEDIR}${PREFIX}/usr/lib/oracle/${ORACLEVERSION}/client/lib
INSTINCSDIR=	${STAGEDIR}${PREFIX}/usr/include/oracle/${ORACLEVERSION}/client
INSTDEMODIR=	${STAGEDIR}${PREFIX}/usr/share/oracle/${ORACLEVERSION}/client

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

LINUXARCH=	linux32
LINUXXVAL=	x86
DISTDATE=	20061115

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=\
	Due to Oracle license restrictions, you must fetch the source\
	distribution manually from\
	http://www.oracle.com/technetwork/database/features/instant-client/index-097480.html\
	, follow the link for Linux ${LINUXXVAL}, download ${DISTFILES}\
	and place it in ${DISTDIR}/${DIST_SUBDIR}/
.endif

do-install:
	${MKDIR} -m 0755 ${INSTINCSDIR} ${INSTDEMODIR} ${INSTLIBSDIR}
	${LN} -s libclntsh.so.10.1 ${INSTLIBSDIR}/libclntsh.so
	${LN} -s libocci.so.10.1 ${INSTLIBSDIR}/libocci.so
.for i in ${INCS_LIST}
	${INSTALL_DATA} ${WRKSRC}/include/${i} ${INSTINCSDIR}/${i}
.endfor
.for i in ${DEMO_LIST}
	${INSTALL_DATA} ${WRKSRC}/demo/${i} ${INSTDEMODIR}/${i}
.endfor

.include <bsd.port.post.mk>
