# New ports collection makefile for:	ecj-bootstrap
# Date created:				August 2, 2006
# Whom:					NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ecj-bootstrap
PORTVERSION=	3.2
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,%SUBDIR%/,R-${PORTVERSION}-200606291905/,} \
		${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/binaries/:antbin,}
DISTFILES=	eclipse-sourceBuild-srcIncluded-${PORTVERSION}.zip \
		${ANT_DISTFILE}:antbin
DIST_SUBDIR=	eclipse
EXTRACT_ONLY=	eclipse-sourceBuild-srcIncluded-${PORTVERSION}.zip

MAINTAINER=	maho@FreeBSD.org
COMMENT=	The JDT Core Batch Compiler

USE_ZIP=	yes

BUILD_DEPENDS+= ${LOCALBASE}/libdata/ldconfig/gcc41-withgcjawt:${PORTSDIR}/lang/gcc41-withgcjawt
RUN_DEPENDS+= ${LOCALBASE}/libdata/ldconfig/gcc41-withgcjawt:${PORTSDIR}/lang/gcc41-withgcjawt

ANT_DISTFILE=   apache-ant-${ANT_VERSION}-bin.tar.bz2
ANT_VERSION=    1.6.5

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 700000
IGNORE=	dumps core on 7.x
.endif

GCJ=	gcj41
GIJ=	gij41
JAR=	fastjar41
ANT=	${WRKDIR}/apache-ant-${ANT_VERSION}/bin/ant
GCJDBTOOL=	gcj-dbtool41
WRKSRC=	${WRKDIR}

MAKE_ENV+=	WRKDIR="${WRKDIR}" GCJ="${GCJ}" JAR="${JAR}" GCJDBTOOL="${GCJDBTOOL}"\
		ANT="${ANT}" JAVACMD="${WRKDIR}/gnugcj/bin/gij" PATH="${WRKDIR}/gnugcj/bin:${PATH}"

post-extract:
	@cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/${ANT_DISTFILE} | ${BZIP2_CMD} -d | ${TAR} xf -

pre-build:
	@${MKDIR} ${WRKDIR}/gnugcj/bin
	@${LN} -sf ${LOCALBASE}/bin/${GCJ}  ${WRKDIR}/gnugcj/bin/gcj
	@${LN} -sf ${LOCALBASE}/bin/${GIJ}  ${WRKDIR}/gnugcj/bin/gij

do-build:
	@cd ${WRKDIR} ; ${SETENV} ${MAKE_ENV} ${SH} -x ${FILESDIR}/build.sh

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/ecj-bootstrap-gcj ${PREFIX}/bin
	${LN} -fs ${PREFIX}/bin/ecj-bootstrap-gcj      ${PREFIX}/bin/ecj
	${INSTALL_DATA} ${WRKDIR}/ecj.jar.so           ${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/ecj.jar              ${PREFIX}/share/java/
#	${INSTALL_DATA} ${WRKDIR}/ecj.db              ${PREFIX}/share/gcj-4.1/classmap.d

.include <bsd.port.post.mk>
