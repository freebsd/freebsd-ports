# New ports collection makefile for:	sun-wtk
# Date created:				Mon 12 Apr 2004 19:42:00 EEST
# Whom:					Panagiotis Astithas <past@noc.ntua.gr>
#
# $FreeBSD$
#

PORTNAME=	wtk
PORTVERSION=	2.1
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	sun-
DISTNAME=	j2me_wireless_toolkit-2_1-linux-i386
EXTRACT_SUFX=	.bin

MAINTAINER=	past@noc.ntua.gr
COMMENT=	Sun J2ME Wireless Toolkit

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
ONLY_FOR_ARCHS=	i386
DOWNLOAD_URL=	http://javashoplm.sun.com/ECom/docs/Welcome.jsp?StoreId=22&PartDetailId=J2MEWTK-${PORTVERSION}-G-F&SiteId=JSC&TransactionId=try

RESTRICTED=	License does not allow redistribution of any kind
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

PKGMESSAGE=	${WRKDIR}/pkg-message
APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=You must manually fetch the J2ME WTK self-extracting file for the Linux platform (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} \
	&& dd bs=1024 if=${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		of=${WRKDIR}/j2mewtk-solaris.zip skip=20 2>/dev/null

do-install:
	@${MKDIR} ${APP_HOME}
	@cd ${APP_HOME}  && ${JAR} xf ${WRKDIR}/j2mewtk-solaris.zip 2>/dev/null
	@${SED} -e "s@javapathtowtk=.*@javapathtowtk=${JAVA_HOME}/bin/@" \
		-e "s@/usr/bin/expr@/bin/expr@g" \
		< ${APP_HOME}/bin/ktoolbar > ${APP_HOME}/bin/ktoolbar_
	@${RM} ${APP_HOME}/bin/ktoolbar
	@${MV} ${APP_HOME}/bin/ktoolbar_ ${APP_HOME}/bin/ktoolbar
	@${SED} -e "s@javapathtowtk=.*@javapathtowtk=${JAVA_HOME}/bin/@" \
		-e "s@/usr/bin/expr@/bin/expr@g" \
		< ${APP_HOME}/bin/emulator > ${APP_HOME}/bin/emulator_
	@${RM} ${APP_HOME}/bin/emulator
	@${MV} ${APP_HOME}/bin/emulator_ ${APP_HOME}/bin/emulator
	@${SED} -e "s@javapathtowtk=.*@javapathtowtk=${JAVA_HOME}/bin/@" \
		-e "s@/usr/bin/expr@/bin/expr@g" \
		< ${APP_HOME}/bin/prefs > ${APP_HOME}/bin/prefs_
	@${RM} ${APP_HOME}/bin/prefs
	@${MV} ${APP_HOME}/bin/prefs_ ${APP_HOME}/bin/prefs
	@${SED} -e "s@javapathtowtk=.*@javapathtowtk=${JAVA_HOME}/bin/@" \
		-e "s@/usr/bin/expr@/bin/expr@g" \
		< ${APP_HOME}/bin/utils > ${APP_HOME}/bin/utils_
	@${RM} ${APP_HOME}/bin/utils
	@${MV} ${APP_HOME}/bin/utils_ ${APP_HOME}/bin/utils
	@${SED} -e "s@javapathtowtk=.*@javapathtowtk=${JAVA_HOME}/bin/@" \
		-e "s@/usr/bin/expr@/bin/expr@g" \
		< ${APP_HOME}/bin/defaultdevice > ${APP_HOME}/bin/defaultdevice_
	@${RM} ${APP_HOME}/bin/defaultdevice
	@${MV} ${APP_HOME}/bin/defaultdevice_ ${APP_HOME}/bin/defaultdevice
	@${SED} -e "s@javapathtowtk=.*@javapathtowtk=${JAVA_HOME}/bin/@" \
		-e "s@/usr/bin/expr@/bin/expr@g" \
		< ${APP_HOME}/bin/wscompile > ${APP_HOME}/bin/wscompile_
	@${RM} ${APP_HOME}/bin/wscompile
	@${MV} ${APP_HOME}/bin/wscompile_ ${APP_HOME}/bin/wscompile
	@${CHMOD} ugo+x ${APP_HOME}/bin/*
	@${CHMOD} ugo-x ${APP_HOME}/bin/*.jar
	@${MV} ${APP_HOME}/wtklib/Linux ${APP_HOME}/wtklib/FreeBSD
	@${LN} -sf ${APP_HOME}/bin/ktoolbar ${PREFIX}/bin/ktoolbar

post-install:
	@${SED} -e 's,%%PREFIX%%,${APP_HOME},' \
		< ${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
