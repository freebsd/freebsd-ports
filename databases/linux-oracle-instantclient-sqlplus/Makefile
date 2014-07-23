# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=		instantclient
PORTVERSION=		${ORACLEVERSION}.${DISTDATE}
PORTREVISION=		3
CATEGORIES=		databases
MASTER_SITES=		#http://www.oracle.com/technology/software/tech/oci/instantclient/
PKGNAMEPREFIX=		linux-oracle-
PKGNAMESUFFIX=		-sqlplus
DISTNAME=		${PORTNAME}${PKGNAMESUFFIX}-${LINUXARCH}-${ORACLEVERSION}-${DISTDATE}
DIST_SUBDIR=		oracle

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Oracle 10 32 Bit Linux InstantClient SQLPlus for RDBMS 8.1.2+

ONLY_FOR_ARCHS=		i386 amd64
NO_BUILD=		yes
DISTINFO_FILE=		${MASTERDIR}/distinfo.i386

RESTRICTED=		Packaging prohibited by Oracle license

USES=			zip
USE_LINUX=		yes
USE_LINUX_PREFIX=	yes

ORACLEVERSION=		10.2.0.3

BINS_LIST=		sqlplus

LIBS_LIST=		glogin.sql	\
			libsqlplus.so	\
			libsqlplusic.so

WRKSRC=			${WRKDIR}/instantclient_10_2

INSTBINSDIR=		${STAGEDIR}${PREFIX}/usr/bin
INSTLIBSDIR=		${STAGEDIR}${PREFIX}/usr/lib/oracle/${ORACLEVERSION}/client/lib

USE_LDCONFIG=		${PREFIX}/usr/lib/oracle/${ORACLEVERSION}/client/lib

PLIST_SUB=		ORACLEVERSION=${ORACLEVERSION}

.include <bsd.port.pre.mk>

#.if ${ARCH} == "i386"
LINUXARCH=		linux32
DISTDATE=		20061115
#.elif ${ARCH} == "amd64"
#LINUXARCH=		linux-x86-64
#DISTDATE=		20070103
#.endif

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE+=	due to Oracle license restrictions, you must fetch the source distribution manually from http://www.oracle.com/technology/software/tech/oci/instantclient/index.html , follow the link for ${DISTFILES} and place them in ${DISTDIR}/${DIST_SUBDIR}/
.endif

do-install:
	@${MKDIR} -m 0755 ${INSTBINSDIR}
	@${MKDIR} -m 0755 ${INSTLIBSDIR}
.for i in ${BINS_LIST}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${INSTBINSDIR}/${i}
.endfor
.for i in ${LIBS_LIST}
	${INSTALL_DATA} ${WRKSRC}/${i} ${INSTLIBSDIR}/${i}
.endfor

.include <bsd.port.post.mk>
