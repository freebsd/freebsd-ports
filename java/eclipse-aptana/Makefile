# New ports collection makefile for:	eclipse-aptana
# Date created:		2007-11-14
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aptana
PORTVERSION=	1.1.7.015414
#PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	java devel
MASTER_SITES=	http://update.aptana.com/install/studio/${ECLIPSE_VER}/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	aptana_update_${PORTVERSION:E}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Aptana Web Development Tools (Eclipse plugin)

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

ECLIPSE_VER=	3.2

JAVA_OS=	native
JAVA_VENDOR=	bsdjava
JAVA_VERSION=	1.5+

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_JAVA=	yes
USE_ZIP=	yes

post-extract:
	@cd ${WRKDIR}; \
	${MKDIR} ${WRKDIR}/eclipse; \
	DIRS=$$(${FIND} . -type d -mindepth 1 -not -name eclipse); \
	for DIR in $${DIRS}; do \
	    FILES=$$(${FIND} $${DIR} -type f -name "*.jar"); \
	    ${MKDIR} ${WRKDIR}/eclipse/$${DIR}; \
	    for FILE in $${FILES}; do \
		JARDIR=$$(${BASENAME} $${DIR})/$$(${BASENAME} $${FILE} .jar); \
		${UNZIP_CMD} -o $${FILE} -d ${WRKDIR}/eclipse/$${JARDIR}; \
	    done; \
	done;

do-install:
	@cd ${WRKDIR} && ${CP} -R eclipse ${PREFIX}/;

post-install:
	@cd ${WRKDIR}; \
	${ECHO_CMD} "@comment pkg-plist automatically generated" >> ${TMPPLIST}; \
	${FIND} -s eclipse -type f -exec ${ECHO_CMD} {} ";" >> ${TMPPLIST}; \
	${FIND} -s eclipse -type d | ${SORT} -r | ${GREP} -vE '^eclipse$$|^eclipse/plugins$$|^eclipse/features$$' | ${SED} -ne 's,^,@dirrm ,p' >> ${TMPPLIST};

.include <bsd.port.mk>
