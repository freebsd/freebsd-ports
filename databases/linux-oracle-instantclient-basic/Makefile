# New ports collection makefile for:	linux-oracle-instantclient-basic
# Date created:				03 June 2004
# Whom:					Alexander Novitsky
#
# $FreeBSD$
#

PORTNAME=		instantclient
PORTVERSION=		10.1.0.3
CATEGORIES=		databases
MASTER_SITES=		#http://www.oracle.com/technology/software/tech/oci/instantclient/
PKGNAMEPREFIX=		linux-oracle-
PKGNAMESUFFIX=		-basic
DISTNAME=		${PORTNAME}${PKGNAMESUFFIX}-linux32-${PORTVERSION}
DIST_SUBDIR=		oracle

MAINTAINER=		alecn2002@yandex.ru
COMMENT=		Oracle 10 InstantClient basics. Works with Oracle RDBMS 8.1.2+

ONLY_FOR_ARCHS=		i386
# Couldn't test for IA64, so commented it out
# ONLY_FOR_ARCHS+=	ia64
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes

RESTRICTED=		Packaging prohibited by Oracle license

USE_ZIP=		yes
USE_LINUX_PREFIX=	yes

LIBS_LIST=		libclntsh.so.10.1 \
			libnnz10.so \
			libocci.so.10.1 \
			libociei.so \
			libocijdbc10.so \
			libocci10_296.so.10.1

WRKSRC=			${WRKDIR}/instantclient10_1

INSTLIBSDIR=		${PREFIX}/usr/lib/oracle/${PORTVERSION}/client/lib

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
			@${MKDIR} -m 0755 ${INSTLIBSDIR}
.for i in ${LIBS_LIST}
			${INSTALL_DATA} ${WRKSRC}/${i} ${INSTLIBSDIR}/${i}
.endfor
			${ECHO_CMD} "${INSTLIBSDIR:S,${PREFIX},,}" >> ${PREFIX}/etc/ld.so.conf
			${PREFIX}/sbin/ldconfig

.include <bsd.port.post.mk>
