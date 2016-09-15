# Created by: Alexander Novitsky
# $FreeBSD$

PORTNAME=		instantclient
PORTVERSION=		${ORACLEVERSION}.${DISTDATE}
PORTREVISION=		5
CATEGORIES=		databases
MASTER_SITES=		#http://www.oracle.com/technology/software/tech/oci/instantclient/
PKGNAMEPREFIX=		linux-oracle-
PKGNAMESUFFIX=		-basic
DISTNAME=		${PORTNAME}${PKGNAMESUFFIX}-${LINUXARCH}-${ORACLEVERSION}-${DISTDATE}
DIST_SUBDIR=		oracle

MAINTAINER=		pi@FreeBSD.org
COMMENT=		Oracle 10 32Bit Linux InstantClient basics for RDBMS 8.1.2+

ONLY_FOR_ARCHS=		i386 amd64
NO_BUILD=		yes
DISTINFO_FILE=		${MASTERDIR}/distinfo.i386

RESTRICTED=		Packaging prohibited by Oracle license

USES=			linux zip
USE_LINUX_PREFIX=	yes

ORACLEVERSION=		10.2.0.3

BINS_LIST=		genezi

LIBS_LIST=		libclntsh.so.10.1	\
			libnnz10.so		\
			libocci.so.10.1		\
			libociei.so		\
			libocijdbc10.so		\
			ojdbc14.jar

WRKSRC=			${WRKDIR}/instantclient_10_2

INSTBINSDIR=		${STAGEDIR}${PREFIX}/usr/bin
INSTLIBSDIR=		${STAGEDIR}${PREFIX}/usr/lib/oracle/${ORACLEVERSION}/client/lib

USE_LDCONFIG=		yes

PLIST_SUB=		ORACLEVERSION=${ORACLEVERSION}

.include <bsd.port.pre.mk>

#.if ${ARCH} == "i386"
LINUXARCH=		linux32
LINUXXVAL=		x86
DISTDATE=		20061115
#.elif ${ARCH} == "amd64"
#LINUXARCH=		linux-x86-64
#DISTDATE=		20070103
#.endif

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=\
	Due to Oracle license restrictions, you must fetch the source\
	distribution manually from\
	http://www.oracle.com/technetwork/database/features/instant-client/index-097480.html\
	, follow the link for Linux ${LINUXXVAL}, download ${DISTFILES}\
	and place it in ${DISTDIR}/${DIST_SUBDIR}/
.endif

do-install:
	${MKDIR} -m 0755 ${INSTBINSDIR}
	${MKDIR} -m 0755 ${INSTLIBSDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/ld.so.conf.d
	${ECHO} /usr/lib/oracle/${ORACLEVERSION}/client/lib > ${STAGEDIR}${PREFIX}/etc/ld.so.conf.d/oracle10.conf
.for i in ${BINS_LIST}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${INSTBINSDIR}/${i}
.endfor
.for i in ${LIBS_LIST}
	${INSTALL_DATA} ${WRKSRC}/${i} ${INSTLIBSDIR}/${i}
.endfor

.include <bsd.port.post.mk>
