# New ports collection makefile for:	zh-tatter-tools
# Date created:		2005-11-10
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tatter-tools
PORTVERSION=	0.9.6
CATEGORIES=	chinese www
MASTER_SITES=	ftp://bbs.ilc.edu.tw/chinsan/distfiles/ \
		http://bbs.ilc.edu.tw/~chinsan/ports/tatter-tools/ \
		ftp://news.giga.net.tw/chinsan/distfiles/ \
		http://www.twtt.org/ttfile/
DISTNAME=	${PORTNAME}-${PORTVERSION}.zh_TW.UTF-8

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	Cute and easy blog Tool with Traditional-Chinese(zh_TW.UTF-8)

USE_PHP=	mysql pcre session xml
NO_BUILD=	YES
WANT_PHP_WEB=	YES

TMPDIR?=	${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKDIR}/${TMPDIR}

.if defined(WITH_MYSQL5)
IGNORE=		Please take a look at http://www.twtt.org/viewtopic.php?t=192&highlight=bsd for soultion
.endif

.if !defined(TT_URL)
pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define TT_URL to override default of ${PREFIX}/${WWWDOCROOT}/'${TT_URL}'."
	@${ECHO_MSG} ""
.endif

# Get HOSTNAME
.if exists(/sbin/sysctl)
HOSTNAME!=	/sbin/sysctl -n kern.hostname
.else
HOSTNAME!=	/usr/sbin/sysctl -n kern.hostname
.endif

WWWDOCROOT?=	www/data
TT_URL?=	tatter
TT_DIR?=	${WWWDOCROOT}/${TT_URL}
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

pre-install:
	@cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${TT_DIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${TT_DIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${TT_DIR} >> ${PLIST}

do-install:
	-${MKDIR} ${PREFIX}/${TT_DIR}
	@${CHMOD} 755 ${PREFIX}/${TT_DIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${TT_DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TT_DIR}
	@${CHMOD} 777 ${PREFIX}/${TT_DIR}/

post-install:
	@${SED} -e 's|%%HOSTNAME%%|${HOSTNAME}|; s|%%TT_URL%%|${TT_URL}|' \
		${PKGMESSAGE}

.include <bsd.port.post.mk>
